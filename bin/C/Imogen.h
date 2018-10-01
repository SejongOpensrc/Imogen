int Log(const char *szFormat, ...);

typedef struct Image_t
{
	int width, height;
	int components;
	void *bits;
} Image;

typedef struct Evaluation_t
{
	int targetIndex;
	int inputIndices[8];
	int forcedDirty;
} Evaluation;

typedef struct Mesh_t
{
	float bboxMin[3];
	float bboxMax[3];

	float cameraPos[3];
	float cameraTarget[3];
} Mesh;

// call FreeImage when done
int ReadImage(char *filename, Image *image);
// writes an allocated image
int WriteImage(char *filename, Image *image, int format, int quality);
// call FreeImage when done
int GetEvaluationImage(int target, Image *image);
// 
int SetEvaluationImage(int target, Image *image);
// call FreeImage when done
// set the bits pointer with an allocated memory
int AllocateImage(Image *image);
int FreeImage(Image *image);

// Image resize
// Image thumbnail
int SetThumbnailImage(Image *image);

// force evaluation of a target with a specified size
// no guarantee that the resulting Image will have that size.
int Evaluate(int target, int width, int height, Image *image);


int ReadMesh(char *filename, Mesh *mesh);
int SetEvaluationMesh(int target, Mesh *mesh);
#define EVAL_OK 0
#define EVAL_ERR 1