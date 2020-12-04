 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "Ҵ��");
        set("long", @LONG
����һ��С�ţ�ƽ�����ǹ��ŵģ��������������ƥ�������Դ�����ֱ
�����������ǽ����������ӳ������һ����ζ�������ȥ���ǳ����������
LONG
        );
        set("exits", ([ 
  "westdown" : __DIR__"shandan",
  "northwest" : __DIR__"yingbi",
]));
        set("objects", ([
                __DIR__"npc/monk4" : 2,
       ]) );
        set("outdoors", "shaolinfy");
        set("coor/x",-200);
        set("coor/y",160);
        set("coor/z",40);
        setup();
}
int valid_leave(object me, string dir)
{
        object *inv;
        object ob;
        int i;
        if( userp(me))
        {
        if( me->query("class") != "shaolin" && dir == "northwest" && ob=present("shaolin monk", this_object()))
        {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                        if(inv[i]->query("shaolin_cloth") && (int)inv[i]->query("equipped"))
                                return 1;
                return notify_fail(ob->name()+"���㹰�ֵ���û����ɽ�ƣ��Ƕ��ֵ��Ӳ������ڣ���\n");
        }
        return 1;
        }
        else return 1;
} 
void reset()
{
        object *inv, ob;
        string *sname=({"Բ��","Բ��",});
        int i;
        ::reset();
        ob=present("shaolin monk", this_object());
        if(ob) ob->set("name","Բ��");
        if(ob) ob->set("chat_chance_combat",50);
        inv = all_inventory();
        if(ob)  {
                ob->dismiss_team();
                for(i=0;i<sizeof(inv);i++)
                        if(inv[i]->query("id") == "shaolin monk" && inv[i] != ob)
                        if(i<=1) {
                        ob->add_team_member(inv[i]);
                        inv[i]->set("name",sname[i]);
                        inv[i]->set("chat_chance", 2);
                        inv[i]->set("chat_msg", ({
                                inv[i]->name()+"˵������˵���������˴�ľ�������ɽȥ�ˣ�\n",
                        }) );
                }
        }
} 
