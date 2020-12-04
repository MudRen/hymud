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
        set("objects",([
                __DIR__"npc/qinggirl" : 1,
        ]) );
        set("exits", ([ 
                "east" : __DIR__"uproad0",
                "westdown" : __DIR__"uproad2",
        ]));
        set("outdoors", "tieflag");
        set("coor/x",2000);
        set("coor/y",-200);
        set("coor/z",15);
        setup();
}
int valid_leave(object who,string dir)
{
    object platform;
    if (!objectp(platform=find_object(__DIR__"platform")))
        platform=load_object(__DIR__"platform");
        if(userp(who) && !random(3) && dir=="east")
        {
                who->move(platform);
                return notify_fail(""); 
        }
        return 1;
}    
