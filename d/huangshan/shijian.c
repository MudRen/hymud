 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�Խ�ʯ");
        set("long", @LONG
һ��޴��ʯͷ���´�·�У��м�һ�ۣ�����룬�ഫ����һ�Ŵ���ʦ�Խ�
֮��������ǧ�࣬����������һ�ѿ���������ʯ�Ľ�����Ϊ������񽣡�����ϧ��
ʦ�������㲶������ഫ��ɽ��®���������ഫ�ı��Ǵ˽���
LONG
        );
        set("exits", ([ 
        "north"  : __DIR__"zuishi",
        ]));
        set("item_desc", ([
"stone": "һ��޴��ʯͷ���м�һ�ۣ��ѷ���ƺ���һ
�����������⡣���ƺ�Ҳ������������һ�ԣ������������������\n",
                "ʯͷ": "һ��޴��ʯͷ���м�һ�ۣ��ѷ���ƺ���һ
�����������⡣���ƺ�Ҳ������������һ�ԣ������������������\n"
        ]) );
    
        set("outdoors", "huangshan");
        set("coor/x",-550);
        set("coor/y",-530);
        set("coor/z",10);
        setup();
}
void init()
{
        add_action("do_test","test");
} 
int do_test(string arg)
{
        object me,weapon;
        if(!arg ) return notify_fail("��Ҫ��һ�������ϵ�����������\n");
        me=this_player();
        if(!(weapon = present(arg,me))) return notify_fail("�������ƺ�û������������\n");
        if(!weapon->query("weapon_prop")) return notify_fail(weapon->name()+"�ƺ�������һ��������\n");
        if(!weapon->query("equipped")) return notify_fail("�㲢û�н�"+weapon->name()+"�������С�\n"); 
        message_vision("$N�þ�ȫ���������е�"+weapon->name()+"�������ʯ��ȥ��������\n",me);
   weapon->unequip();
        if(weapon->query("owner")){
                weapon->set("orig_name", weapon->query("name"));
                weapon->set("weapon_prop/damage",1);
        weapon->set("item_damaged", 1);
        } else {
                weapon->set("weapon_prop",0);
        }
//      weapon->save();
        me->reset_action();
        message_vision("ֻ������������һ����$N���е�"+weapon->name()+"Ӧ�����ϣ�\n",me);
        weapon->set("name","�ϵ���" + weapon->query("name"));
        weapon->set("item_damaged", 1);
        weapon->set("value",0);
        weapon->save();
        if(random(500)||(int)me->query_temp("OldIronOut")>=1)           //modified by justdoit at Jan 14,2002
        tell_object(this_object(),"��ʯ�ϵ��Ѻ��ƺ�������һЩ��\n");
        else {
        message_vision("һ�������Ķ�����ʯ���е��˳�������$N���У�\n", me);
        weapon = new(__DIR__"obj/banzhi");
        weapon->move(me);
        me->add_temp("OldIronOut",1);           //modified by justdoit at Jan 14,2002
        }
        me->start_busy(2);
        return 1;
} 
int valid_leave(object me, string dir)          //add by jusdoit at Jan 14,2002
{
        object ob;
        if( dir == "north" && (int)me->query_temp("OldIronOut") ) {
                me->delete_temp("OldIronOut");
                return 1;
                }
        else
                return 1;
} 
