 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
վ���������΢����棬��ˬ���ˣ����ƺ������������վ���������
�ܣ�һ����ɽ��Ȼ������ɽ��ʯɽ���֣�����������������ʹ��������ʯ��
������Ŀ��������ɽǰ����һ���й����������ս�������бָ��ɽ��
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"realhole",
  "east" : __DIR__"bladem",
]));
        set("objects", ([
        __DIR__"npc/girls" : 2,
                        ]) ); 
        set("outdoors", "palace"); 
        set("coor/x",200);
        set("coor/y",-40);
        set("coor/z",20);
        set("coor/x",200);
        set("coor/y",-40);
        set("coor/z",20);
        setup();
        replace_program(ROOM);
}        
