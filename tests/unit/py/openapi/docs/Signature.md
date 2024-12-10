# Signature


## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**signed_hash** | **str** |  | 
**s_value** | **str** |  | [default to '']
**r_value** | **str** |  | [default to '']
**op** | **str** |  | [default to '']

## Example

```python
from openapi_client.models.signature import Signature

# TODO update the JSON string below
json = "{}"
# create an instance of Signature from a JSON string
signature_instance = Signature.from_json(json)
# print the JSON string representation of the object
print(Signature.to_json())

# convert the object into a dict
signature_dict = signature_instance.to_dict()
# create an instance of Signature from a dict
signature_from_dict = Signature.from_dict(signature_dict)
```
[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


