inherit ROOM;

void create()
{
        set("short", "�ɽ���");
        set("long", @LONG
������������Ļ�ͤ����ϵ��ɽ��أ���ͤ������֣�Ҳ
�Ǹ��̴���Ƽ�֮�����ɻ�ͤ���̻���ơ�
LONG
        );


	set("exits",([
	"east" : __DIR__"lu13",
]));
  	set("objects",([
"quest/skills2/wunon/non/nontian" : 3,
	"/clone/npc/man" : 2,
]));

 
        setup();
}

