 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�˴���Ϊ�տ����ıڿ���һ��������һ��ʯƺ��ƺ����һ��
����ʯ�̾͵����̣��̱߸���һ������С�У�������װ���ӵġ�ʯ
ƺ���Ҹ���һ����档
LONG
        );
        set("exits", ([
                "east" : __DIR__"shushi",
            "west" : __DIR__"qinshi",
        ])); 
        set("objects", ([
        __DIR__"npc/tong2": 1,
    ])); 
        set("coor/x",3280);
        set("coor/y",30);
        set("coor/z",-20);
        setup();
}     
