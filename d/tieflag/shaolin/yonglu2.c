 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�·");
        set("long", @LONG
һ��խ���ߵ�ͨ�����ƺ���ȫ�ü�Ӳ�Ļ����Ҵ���ġ�
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"changjing",
  "southup" : __DIR__"daxiong",
]));
        set("objects", ([
                __DIR__"npc/monk" : 11,
       ]) );
        set("coor/x",-210);
        set("coor/y",220);
        set("coor/z",40);
        setup();
}
int valid_leave(object me, string dir)
{
        object ob; 
if( userp(me) &&
dir=="northup" && ob=present("shaolin monk", this_object())
&& me->query("vendetta/shaolin")>=1)
return notify_fail("���кȵ�:����ֹ��!\n");     
        
if( userp(me) &&
dir=="northup" && ob=present("shaolin monk", this_object())
&& me->query("family/family_name") != "������")
return notify_fail( "����˵������λʩ�����Ƕ��ֵ��Ӳ�������ǰ���ˣ�\n");
return 1;
}  
void reset()
{
object *inv, ob;
string *sname=({"����","�λ�","��ʧ","�ζ�","����","�ζ�","����",
"�γ�","�ο�","��԰", "����" });
int i ;
::reset();
ob=present("shaolin monk", this_object());
if(ob) ob->set("name","����");
if(ob) ob->set("chat_chance_combat",50);
inv = all_inventory();
if(ob)
{
ob->dismiss_team(); 
for(i=0 ;i < sizeof(inv);i++)
        if(inv[i]->query("id") == "shaolin monk" && inv[i]!= ob)
        {
        if (i<7 ) ob->add_team_member(inv[i]);
        if (i<11 ) inv[i]->set("name",sname[i]);        
        }
}
}     
