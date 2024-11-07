from flask import Flask, request, jsonify, session, render_template, send_file
from werkzeug.utils import secure_filename
import os
import hashlib
import importlib
import random
import Magikarp # 잉어


app = Flask(__name__)
app.secret_key = "잉어잉어"

os.environ['FLAG_B'] = "_make_a_splash!}"

def generate_own_karp():
    karp_poses = Magikarp.generate_random_karp(session["sessid"])
    for name, data in karp_poses.items():
        with open("./sessions/" + session["sessid"] + "/files/" + name+".png", "wb") as img_file:
            img_file.write(data) 

@app.route("/", methods=["GET"])
@app.route("/index")
def index():
    print(session)
    if "sessid" not in session:
        rand_hash = hashlib.md5(("잉어" + str(random.randint(0, 999999))).encode("utf-8")).hexdigest()
        session["sessid"] = rand_hash
    if not os.path.exists("./sessions/" + session["sessid"]):
        os.makedirs("./sessions/" + session["sessid"] + "/files/")
        generate_own_karp()
        with open("move.py", "r", encoding="utf-8") as f:
            data = f.read()
        with open("./sessions/" + session["sessid"] + "/move.py", "w", encoding="utf-8") as f:
            f.write(data)
    return render_template("index.html")

@app.route("/splash", methods=["GET"])
def splash():
    try:
        result = importlib.reload(
            importlib.import_module("sessions." + session["sessid"] + ".move")
        ).splash()
        return jsonify({"status": "ok", "move": "튀어오르기", "result": result})
    except:
        return jsonify({"status": "error"})


@app.route("/imageUpload/<contentname>", methods=["POST"])
def upload_content(contentname):
    contents_uploadable = ["field"]
    if not contentname in contents_uploadable: 
        return jsonify({"status": "error"})

    f = request.files["file"]
    fname = secure_filename(f.filename)
    fpath = "./sessions/" + session["sessid"] + "/files/" + fname
    try:
        f.save(fpath)
        session["content."+contentname] = fname
        return jsonify({"status": "ok", "field": fpath})
    except:
        return jsonify({"status": "error"})

@app.route("/content/<contentname>", methods=["GET"])
def content(contentname):
    return send_file(os.path.join("sessions", session["sessid"], "files", session["content."+contentname]), mimetype="image/png")

@app.route("/image/<filename>", methods=["GET"])
def image(filename):
    return send_file(os.path.join("sessions", session["sessid"], "files", filename), mimetype="image/png")



if __name__ == "__main__":
    app.run(debug=True)
