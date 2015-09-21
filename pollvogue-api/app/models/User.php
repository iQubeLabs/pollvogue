<?php

use Illuminate\Database\Eloquent\Model as Eloquent;

class User extends Eloquent {

	/**
	 * The database table used by the model.
	 *
	 * @var string
	 */
	protected $table = 'userinfo';

	/**
	 * The attributes excluded from the model's JSON form.
	 *
	 * @var array
	 */
	//protected $hidden = array('password', 'deleted_at');

	public $timestamps = true;
}