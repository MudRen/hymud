// xiaoxiang.c
// by dicky

inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
����һ���ڰ��������С������з·�Ʈ����һ��������Ϣ����
����ͨ��С��������˾����ǲ������Ǳ���ȥ�ġ�������һ���ƾɵ���
�ӣ���ǰ����һֻ���Ź����������߾ͻ�ص����д�·�ˡ�
LONG
        );

        set("outdoors", "houjizhen");

        set("exits", ([ /* sizeof() == 2 */
  	"west" : __DIR__"minju2",
  	"northwest" : __DIR__"xiaoxiang1",
  	"southeast" : __DIR__"shilu5",
]));
        
        set("objects", ([
                __DIR__"npc/dog": 1,
	]));

        setup();
        replace_program(ROOM);
}


