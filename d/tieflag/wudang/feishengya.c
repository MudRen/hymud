 inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������һ��ͻ��������ڣ�ɽ������һ��С·ֱ����ۣ�Ծ��
����������������Ȼ��Զ��
LONG
        );
        set("exits", ([
        "westup" : __DIR__"tianzhufeng",
        ]));
        set("outdoors", "wudangfy");
        set("coor/x",120);
        set("coor/y",-180);
    set("coor/z",90); 
        set("objects", ([
        __DIR__"npc/yidianhong": 1,
        ]) );
        setup(); 
}    
