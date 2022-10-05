public function do_login(){
    $info = M('User')->where(['username'=>I('username'),'userpass'=>('userpass')])->find();
    if($info){
        session('userId',$info['user_id']);
        $this->ajaxReturn($info['user_id']);
    }else{
        $this->ajaxReturn("-1");
    }
}