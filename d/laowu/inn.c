 inherit ROOM;
void create()
{
        set("short", "С��ջ");
        set("long", @LONG
��ª�Ŀ������й���һ��������Ԫ���Ĳ���ү�������һ�����ϣ�������ϴ�ķ���
�����������������滹�����Ŷ���ĺ조ϲ���֣�����˭�߽���������Կ��ó����
�������ˣ�һ�������������ŷ����ε���С�ӡ�
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"street2",
  "east" : __DIR__"pofang",
]));
        set("objects", ([
        __DIR__"npc/waiter" : 1,
                        ]) );
       set("coor/x",20);
        set("coor/y",12060);
        set("coor/z",0);
        setup();
        replace_program(ROOM); 
}   
