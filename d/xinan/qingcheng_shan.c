inherit ROOM;


void create()
{
   set("short","���ɽ��");
   set("long",@LONG
���������ɽ���£�������صؽ硣����ɽ��·�գ�ç�ֱ��գ���˵����ǿ��
��û���򶫿��ẽ�������ɶ��ǲ�Զ�ˡ�
LONG);
   set("exits",([
     	"east" 		:	__DIR__"dujiang_yan",
     	"north" 	:	 __DIR__"cunzi/lroad1",
  	"west"		:	 __DIR__"after_qingcheng/qingcheng_shan1",
        "south"    : "/d/qingcheng/path1",
  	
    ]));
    
	set("objects", ([
                "quest/skills2/wunon/dalie/dalie" : 2,
	]));
    
   setup();
   set("outdoors","xinan");
} 
