
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
        set("outdoors","xueting");

        setup();
        replace_program(ROOM);
}

