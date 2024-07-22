#pragma once

class ResourceBase;
class LineMesh;

class ResourceManager
{
public:
	DECLARE_SINGLE(ResourceManager);
	~ResourceManager();

public:
	void Init();
	void Clear();

	const LineMesh* GetLineMesh(wstring hey);

private:
	unordered_map<wstring, LineMesh*> _lineMeshes;
};

