 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�ؾ�¥");
        set("long", @LONG
������һ�ؾ�������ǰ��ؾ���ͬ���ǣ��������ٷ�Ҿ���
��������¸��Ÿ��ɵ��书�ؼ�������������Ϊ���ֱ��������ӱ���
�£��������书�������ԣ��˾���Ҳ���Ƕ�����ѧǧ�겻˥�İ�����
�ڡ�
LONG
        );
        set("exits", ([ 
  "northeast": __DIR__"xueshen",
  "northwest" : __DIR__"yangxing",
  "up" : __DIR__"cj2",
  "south": __DIR__"damo",
]));
        set("objects", ([
                __DIR__"npc/monk7" : 2,
       ]) );
        set("coor/x",-210);
        set("coor/y",360);
        set("coor/z",70);
        setup(); 
}
void shouyu_notify()
{
object me,ob;
me = this_player();
if(ob = present("shaolin monk",this_object()))
{
message_vision("$N��$n˵�������������ģ�Ҫ�ӱ�С�ģ�\n",ob,me);
me->set_temp("okey_go_up",1); 
}
return;
}
int valid_leave(object me,string dir)
{
        object ob;
if(userp(me) && dir == "up" && ob=present("shaolin monk",this_object()))
{
if(me->query_temp("okey_go_up")) {
me->delete_temp("okey_go_up");
return 1;
}
else
{
message_vision("$N��$n����û�з��ɵ��ױ����Ͳ�����¥��\n",ob,me);
return notify_fail("");
}
}
me->delete_temp("okey_go_level4");
return 1;
} 
