// diaoyuchi.c
inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
������һ��СС��ˮ�أ��Ա��в��ٵ������ڴ������ۣ�����
�ߵ��ϸ��Ȼ������һ�������صĴ����㰡������ʲô����������
�߻����ż�������ˣ�������fish���ɡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	"north" : __DIR__"path5",
]));
        set("roomlevel","1");setup();
}
void init()
{
        add_action("do_fish", "fish");
}

int do_fish()
{
        object me;
        //, fish;
        int i, kar, cps, bb;
        me = this_player();
        if(me->is_busy())
             return notify_fail("�㻹�ǵ�����������ڷŸ˰ɣ�\n");
        if(me->query("qi")<10)
             return notify_fail("�㻹������Ϣһ�°ɣ������ǵ�һλ�ġ�\n");
         if (me->query("combat_exp") > 35000)
             return notify_fail("���Ѿ�����ͨ���������Ӿ����ˡ� \n");
        me->start_busy(2);
//        call_out("fliping",1,me);
        message_vision("$N����һ����������ڴ�ʯͷ�ϵ�����������\n", me);
        for (i=0; i<200000; i++) ;
        message_vision("$Nֻ����Ư��Ȼһ������æ��ˡ�\n",me);
        kar = me->query("kar");
        cps = me->query("cps");
        if (random(kar+cps)>((kar+cps)/10)*9) {
                message_vision("$N����һ��������\n", me);
                if(me->query("combat_exp")>40000)
                {
                 message_vision("$N�õ���0�㾭��\n",me);  
                }
                else
                {
                 bb=(int)me->query("combat_exp");
                 me->set("combat_exp",3+bb);
                 message_vision("$N�õ���3�㾭��\n",me);  
                }
                me->receive_damage("qi", 10);  
                bb=(int)me->query("potential");
                if(me->query("combat_exp")>40000 )
                {
                 message_vision("$N�õ���0��Ǳ��\n",me);
                }
                else
                {
                 me->set("potential",bb+3);
                 message_vision("$N�õ���3��Ǳ��\n",me);
                }
//              fish = new("/u/c/ckj/npc/obj/fish1");
//              fish->move(me);
                return 1;
        }
        if (random(kar+cps)>((kar+cps)/5)*3) {
                message_vision("$N����һ��������\n", me);
                bb=(int)me->query("combat_exp");
                if(me->query("combat_exp")>40000 )
                {
                 message_vision("$N�õ���0�㾭��\n",me);
                }
                else
                {
                 me->set("combat_exp",2+bb);
                 message_vision("$N�õ���2�㾭��\n",me);
                }
                me->receive_damage("qi", 10);  
                bb=(int)me->query("potential");
                if(me->query("combat_exp")>40000)
                {
                 message_vision("$N�õ���0��Ǳ��\n",me);
                }
                else
                {
                 me->set("potential",bb+2);
                 message_vision("$N�õ���2��Ǳ��\n",me);
                }
//           // fish = new("/u/c/ckj/npc/obj/fish2");
//           // fish->move(me);
                return 1;
        }
        if (random(kar+cps)>((kar+cps)/3)*2) {
                message_vision("$N����һ��������\n", me);
                bb=(int)me->query("combat_exp");
                if(me->query("combat_exp")>40000)
                {
                 message_vision("$N�õ���0�㾭��\n",me);
                }
                else
                {
                 message_vision("$N�õ���1�㾭��\n",me);
                 me->set("combat_exp",1+bb);
                } 
                me->receive_damage("qi", 10);  
                
                bb=(int)me->query("potential");
                if(me->query("combat_exp")>40000)
                {
                 message_vision("$N�õ���0��Ǳ��\n",me);
                }
                else
                {
                 me->set("potential",bb+1);
                 message_vision("$N�õ���1��Ǳ��\n",me);
                }
//           // fish = new("/u/c/ckj/npc/obj/fish2");
//           // fish->move(me);
                return 1;
        }
         else
               me->receive_damage("qi", 10);  
               message_vision("$NʲôҲû������\n",me );
        return 1;}