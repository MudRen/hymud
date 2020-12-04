#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("С��", ({"xiao ma","ma"}) );
        set("title" , "��ŭ��");
        set("gender", "����" );
        set("age", 22);
        set("agi",30);
        set("per", 30);
                set("no_arrest",1);
                set("no_heal",1);
        set("str",100);
        set("long",
        "һ����ǿ��������ȫ�������������Ե�С����˶������з�ŭ��С��\n�������˿ڣ����ƺ����԰��������������壩һ�¡�\n"
        );
        set("force_factor", 50);
        set("max_jing", 3000);
        set("max_qi", 3000);
        set("max_jing", 3000);
        set("eff_jing", 2000);
        set("eff_qi", 2000);
        set("eff_jing", 2000);
        set("jing", 2000);
        set("qi", 2000);
        set("jing", 2000);
        set("max_neili", 2000);
        set("force", 2000);
        set("combat_exp", 2999999);
        set("score", 30000);
        set("chat_chance",1);     
        set("chat_msg",({
                "С���ս���ȭͷ����ŭ�Ļ���������ȼ�ա�\n",
        "��С�գ�С�գ���С����Ϫˮ������ǰ����������ѪȾ�����峺�羵��Ϫˮ��\n",
        }) );
set("max_qi", 13500);
	set("max_jing", 11500);
	set("neili", 23000);
	set("max_neili", 23000);
	set("jiali", 150);

	set("combat_exp", 5900000);
	set("score", 800000);
    set_skill("cuff", 300);
    set_skill("strike", 100);
    set_skill("qingfu-shenfa", 100);
    set_skill("hanbing-mianzhang", 100);
    set_skill("sougu", 100);
    	set_skill("force", 160);
	set_skill("dodge", 140);
	set_skill("sword", 140);
	set_skill("blade", 140);
	set_skill("parry", 140);
	set_skill("cuff", 200);
	set_skill("blade", 140);
	set_skill("jinwu-daofa", 140);
	set_skill("jiuyang-shengong", 260);
	set_skill("lingxu-bu", 140);
    	set_skill("damo-jian", 140);
    	set_skill("qishang-quan", 380);
    	set_skill("hunyuan-zhang", 150);
    	set_skill("literate", 100);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "lingxu-bu");
	map_skill("cuff", "qishang-quan");
    	map_skill("parry", "hunyuan-zhang");
    	map_skill("sword", "damo-jian");
	map_skill("blade", "jinwu-daofa");

	prepare_skill("cuff","qishang-quan");
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/damage", 660);
	set_temp("apply/armor", 660);
	set("chat_chance_combat", 200);
	set("chat_msg_combat", ({
		(: command("perform hunpofeiyang") :),
		(: command("perform youyouhunduan") :),


	}) );
                setup();
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                add_action("do_cure", "cure");
                add_action("do_answer","answer");
                add_action("do_accept","accept");
        }
} 
int do_cure(string arg)
{
        object me;
        me = this_player();
        if( arg != "xiao ma" ) 
                return notify_fail("��ҪΪ˭���ƣ�\n");
        else if( this_object()->query("xiaoma_cured") )
                return notify_fail("С��˵�������鷳�ˣ��ҵ������Ѿ������ˣ�\n");
        else
        {
                if ( me->query("neili") < 1000)
                {
                        return notify_fail("�����������������������������ƣ�\n");
                }
                else
                {
                        write(HIW "��ȫ����ɣ�������ΪС���˹����ˡ�\n"NOR);
                        message_vision(HIW"С����ʹ���Ť�����������ƽ����������������һʱ˵����������\n"NOR , me);
                        me->add("force",-1000);
                        this_object()->set("xiaoma_cured",1);
                        me->start_busy(5);
                        call_out("ask_help", 5, me);
                        return 1;
                }       
        }
        return 1;
} 
void ask_help(object me)
{
        object obj;
        if ( me->query("����B/̩ɽ_�ճ�") )
        {
                message_vision(HIY"С��������۾�ͻȻ������������һ����ֵ�������$N��\n"NOR, me);
                message_vision(HIY"С��ȭ˵������λ"+RANK_D->query_respect(me)+"����֪�Ƿ������Ҿȳ�С�գ���Answer Yes��No��\n"NOR, me);
                me->set_temp("marks/wolf_xiaoma_asking",1);
        }
        else
        {
                message_vision(HIY"һ�����С��������۾�ͻȻ�����������м��Ŀ���$N��\n"NOR, me);
                message_vision(HIY"С����$Nһ��ȭ���������ҵ����Ʋ����󰭣���֪�ɷ����鷳��λӢ�ۣ�\n���Ҿȳ���Ƥ��С�գ�������Accept Yes��No��\n"NOR, me);
                me->set_temp("marks/wolf_xiaoma_questing",1);
                return;
        }
} 
int do_answer(string arg)
{
        object me, obj;
        object room; 
        obj = this_object();
        me =this_player();
        if(!me->query_temp("marks/wolf_xiaoma_asking")) return 0;
        
        if( arg == "yes" || arg == "YES" )
        {
                me->delete_temp("marks/wolf_xiaoma_asking"); 
                message_vision("$N�ս�ȭͷ����С�ձ�̫��ʹ�ߵ�ҩ����ƣ����Ǿ͵�̫�����Ļ�����\n̫��ʹ�߾�һ��ս�������ټ���\n", obj);
                me->set_temp("marks/wolf_xiaoma_good", 1); 
                message_vision("$Nת����Զ���ĺ�����ȥ......\n", obj);
                obj->set("chat_chance",0);   
                room = find_object("/d/wolfmount/flowerboat");
                if(!objectp(room)) room = load_object("/d/wolfmount/flowerboat");
                obj->move(room);
                return 1;
        }
        else if ( arg == "no" || arg == "NO" )
        {
           message_vision("$N��ɫ��Ȼ������"+me->name()+"Ҳ�ﲻ���ң�\n", obj);
                me->delete_temp("marks/wolf_xiaoma_asking"); 
                return 1;
        }
        else 
        {
                tell_object(me, name()+"�����Ҳ������������˼����\n");
                return 1;
        }
} 
int do_accept(string arg)
{
        object me, obj;
        obj = this_object();
        me =this_player();
        if(!me->query_temp("marks/wolf_xiaoma_questing")) return 0;
        
        if( arg == "yes" || arg == "YES" )
        {
                message_vision("$N����Ц������л��λӢ�ۣ�\n", obj);
                me->delete_temp("marks/wolf_xiaoma_questing"); 
                message_vision("$N��ɫ���ص���С�ձ�̫��ʹ�ߵ�ҩ�������ƣ�ֻ��ɱ��̫��ʹ�߲Ż������ƣ�\n", obj);
                me->set_temp("marks/wolf_xiaoma_normal", 1); 
                obj->set("chat_chance",0);
                return 1;
        }
        else if ( arg == "no" || arg == "NO" )
        {
                message_vision("$N��̾һ�������˲������Լ�������ƴ��һ����\n", obj);
                message_vision("$Nת����ȥ���µ�����Ӱ������Զ......\n", obj);
                me->delete_temp("marks/wolf_xiaoma_questing");
                destruct(obj);
                message_vision("$Nʧ�����ǣ������ѵ���Ϊ�Լ���ų����Ϊ�е���ֺ�ڣ�\n",me);
                me->add("score",-100);
                return 1;
        }
        else 
        {
                tell_object(me, name()+"�����Ҳ������������˼����\n");
                return 1;
   }
} 
void die()
{
        object xiaolin;
        if (xiaolin = present("xiao lin",environment(this_object())))
        {
                xiaolin->set("xiaoma_died",1);
        }
        ::die();
}  
