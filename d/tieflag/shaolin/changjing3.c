 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        object ob;
        set("short", "�ؾ���");
        set("long", @LONG
�����������٣��ؾ������Ʊ�����������Ϊ��������
�������ʵ۵�ʥּ�����;��飬��Ϊ���ص����Ǵ�����ͳ�������͵Ĺ�
����ǧ�߰���ʮ�߾�ġ����;����ˣ�����ѵ�����ķ�̾���������
���Խ���������
LONG
        );
        set("exits", ([ 
  "up"  : __DIR__"changjing4",
  "down" : __DIR__"changjing2",
]));
        set("objects", ([
                __DIR__"npc/monk7" : 2,
       ]) );
        set("coor/x",-210);
        set("coor/y",230);
        set("coor/z",70);
        set("no_magic",1);
        setup();
        ob= new(__DIR__"obj/niepan");
        ob->set_amount(6777);
        ob->move(this_object());
}
void shouyu_notify()
{
object me,ob;
me = this_player();
if(ob = present("shaolin monk",this_object()))
{
message_vision("$N��$n˵������Ҫ�����ľ�����¥�ϣ�����¥������������\n",ob,me);
me->set_temp("okey_go_level4",1); 
}
return;
} 
int valid_leave(object me,string dir)
{
        object ob;
if(userp(me) && dir == "up" && ob=present("shaolin monk",this_object()))
{
        if(me->query_temp("okey_go_level4") && !me->query("vendetta/shaolin")) {
                me->delete_temp("okey_go_level4");
                return 1;
        }  else if (me->query("vendetta/shaolin")>0 && me->query_temp("okey_go_level4")) {
                message_vision("$N����һ��,��$n����ɱ�˶��ֵ��ӻ�������¥?\n",ob,me);
                return notify_fail("");
                }
        else {
                message_vision("$N��$n����û�з��ɵ��ױ����Ͳ�����¥��\n",ob,me);
                return notify_fail("");
                }
}
me->delete_temp("okey_go_level4");
return 1;
}     
