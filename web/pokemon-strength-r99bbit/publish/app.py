from yaml import load, FullLoader
from flask import Flask, request, render_template, jsonify
from flask_cors import CORS
import json
import base64

app = Flask(__name__)
CORS(app)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/convert', methods=['POST'])
def convert_yaml_to_json():
    content = request.form['yaml_input']
    try:
        data = load(content, Loader=FullLoader)
        json_output = json.dumps(data, indent=4)
        return jsonify({'json_output': json_output})
    except Exception as e:
        return jsonify({'error': str(e)}), 400

if __name__ == '__main__':
    app.run(debug=False, port=5000, host='0.0.0.0')
