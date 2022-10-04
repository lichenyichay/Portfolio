import java.util.concurrent.Callable
import java.util.concurrent.FutureTask

object HttpUtil {

    private var httpClient = DefaultHttpClient()
    const val BASE_URL = "http://127.0.0.1/api.php/"
    /**
     * @param url 发送请求的URL
     * @return 服务器响应字符串
     * @throws Exception
     */
    @Throws(Exception::class)
    fun getRequest(url:String):String{
        val task = FutureTask(
            Callable<String>{
                // 创建HttpGet对象
                val get = HttpGet(url)
                //发送Get请求
                val httpResponse = httpClient.execute(get)
                //如果服务器成功返回响应信息
                if(httpResponse.getStatusLine().getStatusCode === 200) {
                    return@Callable EntityUtils.toString(httpResponse.getEntity())
                }
                null
            })
        Thread(task).start()
        return task.get()
    }
    /**
     * @param url 发送请求的URL
     * @param rawParams 请求参数
     * @return 服务器响应字符串
     * @throws Exception
     */
    @Throws(Exception::class)
    fun postRequest(url: String, rawParams: Map<String, String>):String{
        val task = FutureTask(
            Callable<String>{
                //创建HttpPost对象
                val post = HttpPost(url)
                val params = ArrayList<NameValuePair>()
                for (key in rawParams.keys){
                    params.add(BasicNameValuePair(key,rawParams[key]))
                }
            })
        return ""
    }
}
