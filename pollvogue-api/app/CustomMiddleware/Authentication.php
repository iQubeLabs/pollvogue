<?php

class Authentication extends \Slim\Middleware {

	const EXPIRY_PERIOD = '+15 days';

	public function call() {
		
		$app = $this->app;
		$resUri = $app->request->getResourceUri();
		$pos = strpos($resUri, 'login');
        $reg = strpos($resUri, 'register');
        $payment = strpos($resUri, 'transaction');
		// $root = $app->request->getRootUri();
		if($pos !== false || $reg !== false || $resUri == "/") {

			$this->next->call();

		} else {

			$token = $app->getCookie('token');
			// Check token if expired!
			if($this->isTokenExpired($token)) {
				
		        $json_output = array();
		        $json_output['meta']["status"] = 9;
		        $json_output['meta']["message"] = "Expired token! Please login to get a valid token";

		        $app->response->header('Content-Type', 'application/json');
		        echo json_encode($json_output);

			} else {
				
				//Update token last use and expiry dates
				$this->next->call();
			}
			
		}
		
	}

	protected function isTokenExpired($token) {

		$usertoken = Usertoken::select('id', 'user_id', 'expires', 'lastusedate')->where('token', '=', $token)
                                ->first();

        if(isset($usertoken)) {
        	//token is valid and exist in the database
	        $expires = $usertoken->expires;
	        $now = date('Y-m-d h:i:s');
	        $env = $this->app->environment();
	        if($now < $expires) {
	        	//token is not expired
	        	$env[$token] = array('user_id' => $usertoken->user_id);

	        	$expirydate = strtotime(TOKEN_EXPIRY_PERIOD);
	            $str_expirydate = date('Y-m-d h:i:s', $expirydate);
	        	$usertoken->lastusedate = $now;
	        	$usertoken->expires = $str_expirydate;
	        	$usertoken->save();
	        	
	        	return false;

	        } else {
	        	//token is expired
	        	unset($env[$token]);
	        	return true;
	        }
	    } else {
	    	return true;
	    }
    
	}

}