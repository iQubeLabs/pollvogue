<?php
/**
 * Created by PhpStorm.
 * User: RotelandO
 * Date: 10/13/14
 * Time: 9:05 PM
 */

use Illuminate\Database\Eloquent\Model as Eloquent;

class ImagePoll extends Eloquent {

    /**
     * The database table used by the model.
     *
     * @var string
     */
    protected $table = 'imagepoll';

    /**
     * The attributes excluded from the model's JSON form.
     *
     * @var array
     */
    protected $hidden = array('deleted_at');

   // public $timestamps = true;
}