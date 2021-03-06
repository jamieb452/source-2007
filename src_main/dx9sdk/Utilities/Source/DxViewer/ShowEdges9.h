//--------------------------------------------------------------------------------------
// Copyright (c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------
#pragma once
#include <vector>
#include "d3d9.h"
#include "d3dx9.h"



namespace Sas
{
    class Effect;
}



class CShowEdges9
{
public:
    CShowEdges9()
    {
        SkinnedVB = NULL;
        LinesIB = NULL;
        Skin = NULL;

        Declaration = NULL;
        Effect = NULL;
    }

    ~CShowEdges9()
    {
        SAFE_RELEASE(SkinnedVB);
        SAFE_RELEASE(LinesIB);
        SAFE_RELEASE(Skin);

        SAFE_RELEASE(Declaration);
        SAFE_RELEASE(Effect);

    }

    void OnLostDevice();
    void OnResetDevice();
    
    void Move(D3DXMATRIX* pBoneTranforms, D3DXMATRIX* pBoneInvTransposes);
    void Draw(const D3DXMATRIX& WorldMatrix);

    void SetMesh(LPD3DXMESH pNewMesh, LPD3DXSKININFO pNewSkin);

private:

    struct Vertex
    {
        D3DXVECTOR3 Position;
    };

    int NumLines;
    int NumPoints;

    LPD3DXSKININFO Skin;
    std::vector<Vertex> UnskinnedVB;
    LPDIRECT3DVERTEXBUFFER9 SkinnedVB;
    LPDIRECT3DINDEXBUFFER9 LinesIB;

    LPDIRECT3DVERTEXDECLARATION9 Declaration;
    ID3DXEffect* Effect;

    static int Stride; 
    static D3DVERTEXELEMENT9 Elements[2]; 

};
