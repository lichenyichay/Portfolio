<?php
$arr = array(
    'code' => '200',
    'msg' => '成功',
    'data' => array(
        'id' => '1',
        'name' => 'Kotlin'
    )
);
$json_string = json_string($arr);
echo $json_string;