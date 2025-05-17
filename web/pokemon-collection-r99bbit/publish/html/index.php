<?php
session_start();
if(!isset($_SESSION["files"]))
    $_SESSION["files"] = array();

?>
<!DOCTYPE html>
<html>
<head>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet">
    <title>포켓몬 도감</title> 
</head>
<body>
<div class="container d-block">
    <div class="mt-5 d-flex justify-content-center">
        <div class="login-form">
            <div id="login">
                <h3>포켓몬 도감</h3>
                <p>포켓몬 사진을 업로드해서 도감을 채워보세요!</p>
                <hr />
                <h5>목록</h5>
                <ul class="list-group">

                <?php
                    foreach($_SESSION["files"] as $f) {
                        ?>
                    <li class="list-group-item"><a href="./download.php?sig=<?=$f[1]?>"><?=$f[0]?></a></li>
                        <?php
                    }
                ?>
                </ul>
                <hr />
                <h5>포켓몬 사진 업로드</h5>
                <form action="file_up.php" method="POST" enctype="multipart/form-data">
                  <div class="mb-3">
                    <label class="form-label">Image</label>
                    <input class="form-control" type="file" name="file">
                  </div>
                  <input class="form-control" type="submit" name="upload">
                </form>
                <hr />
            </div>
        </div>
    </div>
</div>
<script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>