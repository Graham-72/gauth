<?php
/*
 * Copyright 2014 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */

namespace Google\Service\MigrationCenterAPI;

class Operation extends \Google\Model
{
  /**
   * @var bool
   */
  public $done;
  /**
   * @var Status
   */
  public $error;
  protected $errorType = Status::class;
  protected $errorDataType = '';
  /**
   * @var array[]
   */
  public $metadata;
  /**
   * @var string
   */
  public $name;
  /**
   * @var array[]
   */
  public $response;

  /**
   * @param bool
   */
  public function setDone($done)
  {
    $this->done = $done;
  }
  /**
   * @return bool
   */
  public function getDone()
  {
    return $this->done;
  }
  /**
   * @param Status
   */
  public function setError(Status $error)
  {
    $this->error = $error;
  }
  /**
   * @return Status
   */
  public function getError()
  {
    return $this->error;
  }
  /**
   * @param array[]
   */
  public function setMetadata($metadata)
  {
    $this->metadata = $metadata;
  }
  /**
   * @return array[]
   */
  public function getMetadata()
  {
    return $this->metadata;
  }
  /**
   * @param string
   */
  public function setName($name)
  {
    $this->name = $name;
  }
  /**
   * @return string
   */
  public function getName()
  {
    return $this->name;
  }
  /**
   * @param array[]
   */
  public function setResponse($response)
  {
    $this->response = $response;
  }
  /**
   * @return array[]
   */
  public function getResponse()
  {
    return $this->response;
  }
}

// Adding a class alias for backwards compatibility with the previous class name.
class_alias(Operation::class, 'Google_Service_MigrationCenterAPI_Operation');
