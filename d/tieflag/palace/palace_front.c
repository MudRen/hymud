 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���Ž�����ֻ��һ�����ϵ�����ǰ����ǰһ��������ʯ������
�������ޣ������֣��ݺṰ��������̦޺�߲����ּ�������ӳ��
����΢¶��С����
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"palace_gate",
  "eastup" : __DIR__"palace_palace",
]));
        set("outdoors", "palace"); 
        set("coor/x",150);
        set("coor/y",0);
        set("coor/z",30);
        set("coor/x",150);
        set("coor/y",0);
        set("coor/z",30);
        set("coor/x",150);
        set("coor/y",0);
        set("coor/z",30);
        setup();
        replace_program(ROOM);
}      
