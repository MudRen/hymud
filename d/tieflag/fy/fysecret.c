 inherit ROOM;
void create()
{
        set("short", "�����Ÿ�����");
        set("long", @LONG
������С�����õúܾ��¡����ܳ��к��Ǽ򵥣�ֻ��һ�������ƴ��ľ��ÿ��ľ
���ƺ�����ͬһ��Ů�˵����ӣ�����ľ����沿ȫ�ǿհף�����������ľ����˭������
��������һ��С������������һ�����Ͽ�ಣ���Ŀ�԰׵������ˡ�
LONG
        );
        set("exits", ([
                "south" : __DIR__"fyyage",
        ]));
        set("no_magic",1);
        set("NONPC",1);
        set("objects", ([
                __DIR__"npc/lixunhuan": 1,
                __DIR__"obj/muou": 1,
        ]) );
        set("coor/x",10);
        set("coor/y",20);
        set("coor/z",10);
        setup();
        replace_program(ROOM);
}  
