 // searoad.c
inherit ROOM;
void create()
{
        set("short", "ƽ̨");
        set("long", @LONG
��ɽ�����ɣ�����һ��Сͤ����ʯ����������ɹۡ�һ���������ǰ����һ��
����ֱ����ۡ�
LONG
        );
        set("objects",([
                __DIR__"npc/qinggirl1" : 2,
        ]) );
        set("exits", ([ 
                "west" : __DIR__"uproad3",
                "eastup" : __DIR__"uproad4",
        ]));
        set("outdoors", "tieflag");
        set("coor/x",2080);
        set("coor/y",-200);
        set("coor/z",50);
        setup();
}
int valid_leave(object who,string dir)
{   
    object girl;
    girl=present("sword girl",this_object());
    if(girl && living(girl) && userp(who) && who->query("gender")=="����" && dir=="eastup")
        {
                message("vision",girl->name()+"˵��������λ��������������\n",this_object());
                return notify_fail(""); 
        }
        return 1;
}     
