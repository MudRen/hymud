 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��Ժ��");
        set("long", @LONG
�����沢���ߴ��ǽ���ŵô���֮����Ƕ��ֺ�Ժ��Ҳ����������ѧ
�ķ�Դ��--������Ժ��ǽǰվ�ż���������ɮ���ֳֽ䵶����˿������ע
����ǰ����
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"neiyuan",
  "southup" : __DIR__"qianfe",
]));
        set("objects", ([
                __DIR__"npc/monk8" : 2,
       ]) );
        set("outdoors", "shaolinfy");
        set("coor/x",-210);
        set("coor/y",290);
        set("coor/z",60);
        setup();
}
int valid_leave(object me, string dir)
{
        object ob;
        
if( userp(me) &&
dir=="north" && ob=present("shaolin monk", this_object())
&& me->query("vendetta/shaolin")>=1)
return notify_fail("���кȵ�:����ֹ��!\n");
        
if( userp(me) &&
dir=="north" && ob=present("shaolin monk", this_object()) &&
(me->query("family/generation") > 22  ||
me->query("family/family_name") != "������"))
return notify_fail(
"����˵����ֻ�ж��������ҵ��Ӳſ��Խ��붫����Ժ��\n");
return 1;
} 
void reset()
{
object *inv, ob;
string *sname=({"����","�ص�",});
int i;
::reset();
ob=present("shaolin monk", this_object());
if(ob) ob->set("name","����");
if(ob) ob->set("chat_chance_combat",50);
inv = all_inventory();
if(ob)
{
ob->dismiss_team();
for(i=0;i<sizeof(inv);i++)
        if(inv[i]->query("id") == "shaolin monk" && inv[i] != ob)
        if(i<=1) {
        ob->add_team_member(inv[i]);
        inv[i]->set("name",sname[i]);
        }
}
}     
