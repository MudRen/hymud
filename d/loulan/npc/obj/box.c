 inherit ITEM;
void create()
{
        set_name("��ľ�����", ({ "woodcase"}) );
        set_weight(50000); 
        set_max_encumbrance(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("prep", "on");
                set("unit", "��");
                set("long", "һ�ڼ�Ϊ������ľ����䣬��ֻ���ϣ������Żƽ�������ȻҲ�ǻƽ�\n�ģ���������һ�Ѿ޴�ƽ���������������ֶϣ�niu������\n");
                set("value", 1);
        }
        
} 
int is_container() { return 1; } 
void init()
{
        add_action("do_niu","niu");
} 
int do_niu(string arg)
{
        object bai;
        object me;
        me = this_player();
        if(!arg="woodcase"||!arg="��ľ�����") return 0;
        message_vision("$N������������ľ�����Ļƽ���...\n",me);
        if(!query_temp("been_get") && me->query_temp("marks/knight_kill_wang"))
        {
                if (me->query("force_factor") < 50)
                {
                        return notify_fail("��ʹ��ȫ������������ǻƽ���˿��δ��\n");
                }
                else
                {       
                        bai = new("/d/loulan/npc/bai");
                        bai->move(this_object());
                        message_vision("$N�����������ƽ����±Ķ��ϣ���ľ�����ǻ������Զ���������\n",me);
                        set_temp("been_get",1);
                   this_object()->set("closed",0);
                }
        }
        else
        {
                return notify_fail("��û�а취�ֶϻƽ���������ֻ�÷����ˡ�\n");
        }
        return 1;
}    
