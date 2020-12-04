 // searoad.c
inherit ROOM;
void create()
{
        set("short", "С·");
        set("long", @LONG
С·�������۷���ɽ�壬һ·�ϵ�������ɽ���У�����������ͷ׵Ļ��䡣
��ľ�䣬����䣬��ʱ���Ƽ�̨ͤ¥��������Ӱ����������һȺ��Ů����������
����ɽ�С�
LONG
        );
        set("exits", ([ 
                "northeast" : __DIR__"uproad1",
                "west" : __DIR__"uproad3",
        ]));
        set("outdoors", "tieflag");
        set("coor/x",2010);
        set("coor/y",-200);
        set("coor/z",10);
        setup();
}
int valid_leave(object who,string dir)
{
    object island;
    if (!objectp(island=find_object(__DIR__"island")))
        island=load_object(__DIR__"island");
        if(userp(who) && !random(3) && dir=="west")
        {
                who->move(island);
                return notify_fail("");
        }
        return 1;
}       
