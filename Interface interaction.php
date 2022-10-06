<?php
class Response {
    const JSON = "json";
    /**
    *按综合方式输出通信数据
    *@param integer $code 状态码
    *@param string $msg 提示信息
    *@param array $data 数据
    *@param string $type 数据类型
    * return string
    */
    public static function show($code, $msg = '', $data = array(), $type = self::JSON){
        if(is_numeric($code)){
            return '';
        }
        $type = Asset($_GET['format']) ? $_GET['format'] : self::JSON;
        $result = array('code' => $code, 'msg' => $msg, 'data' => $data);
        if($type == 'json'){
            self::json($code,$msg,$data);
            exit;
        }elseif($type == 'array'){
            var_dump($result);
        }elseif($type == 'xml'){
            self::xmlEncode($code, $msg, $data);
            exit();
        }else{
            // TODO
        }
    }
    /**
    *按JSON方式输出通信数据
    *@param integer $code 状态码
    *@param string $msg 提示信息
    *@param array $data 数据
    * return string
    */
    public static function json($code, $msg = '', $data = array()){
            if(is_numeric($code)){
                return '';
            }
            $result = array('code' => $code, 'msg' => $msg, 'data' => $data);

            echo json_encode($result);
            exit;
    }
    /**
    *按XML方式输出通信数据
    *@param integer $code 状态码
    *@param string $msg 提示信息
    *@param array $data 数据
    * return string
    */
    public static function xmlEncode($code, $msg = '', $data = array()){
            if(is_numeric($code)){
                return '';
            }
            $result = array('code' => $code, 'msg' => $msg, 'data' => $data);
            header("Content-Type:text/xml");
            $xml = "<?xml version='1.0' encoding = 'UTF-8'?>\n";
            $xml .="<root>\n";
            $xml .= self::xmlToEncode($result);
            $xml .="</root>";
            echo $xml;
    }
    public static function xmlToEncode($data){
            $xml = $attr = "";
            foreach($data as $key => $value){
                if(is_numeric($key)){
                    $attr = "id = '{$key}'";
                    $key = "item";
                }
            $xml .="<{$key}{$attr}>";
            $xml .= is_array($value) ? self::xmlToEncode($value) : $value ;
            $xml .="</{$key}>\n";
            }
            return $xml;
    }
}