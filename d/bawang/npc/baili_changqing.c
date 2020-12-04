 inherit NPC;
#include <ansi.h>
int proceed(); 
void create()
{
        set_name("���ﳤ��", ({ "baili", "baili changqing"}) );
        set("nickname", HIC "�ɶ�����"NOR);
        set("gender", "����" );
        set("age", 54);
        set("per", 25);
        set("int", 28);
        set("attitude","friendly");
        
        set("force_factor", 30);
        set("max_neili", 1000);
        set("force", 1000);
        set("attitude", "peaceful");
        
        set("combat_exp", 2800000);
        set("score", 90000);
        
     	set("qi", 25000);
	set("max_qi", 25000);
	set("jing", 22400);
	set("max_jing", 22400);
	set("neili", 58000);
	set("max_neili", 58000);
	set("jiali", 300);
	
	set("combat_exp", 8000000);
	set("score", 200000);
	set("shen", 100000);
	 
		set_skill("fengmo-zhang",380);
	set_skill("liuhe-zhang",380);
	set_skill("strike",390);
	set_skill("force", 300);             // �����ڹ�
	set_skill("huntian-qigong", 380);    // ��������
	set_skill("unarmed", 260);           // ����ȭ��
	set_skill("xianglong-zhang", 380);   // ����ʮ����
	set_skill("dodge", 260);      	     // ��������
	set_skill("xiaoyaoyou", 380);        // ��ң��
	set_skill("parry", 260);             // �����м�
	set_skill("staff", 380);             // ��������
	set_skill("dagou-bang", 380);        // �򹷰���
	set_skill("begging", 380);           // �л�����
	set_skill("checking", 380);          // ����;˵
	set_skill("training", 380);         // Ԧ����
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
     
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.hui" :),                
                (: perform_action, "unarmed.fei" :),                
                (: perform_action, "unarmed.qu" :),                
                (: perform_action, "unarmed.zhen" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: perform_action, "unarmed.xianglong" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );
        switch (random(5)) {
                case 0: set("resistance/sen",30);
                        break;
                case 1: set("resistance/gin",30);
                        break;
                default: set("resistance/kee",30);
                }
   
        set("inquiry",  ([
                        "gui dong jing" : (: proceed :),
                        "gui dongjing" :(: proceed :),
                        "guidongjing":(: proceed :),
                        "�鶫��":(: proceed :),
                ]) );
        set("chat_chance",1);
        set("chat_msg",({
                "���ﳤ��Ե˶���������ұ��������ɱ�㣬����......\n\n���а�......��\n",       
        }));    
        set("long",
                "������ĸߴ��ΰ��˫Ŀ���ⱬ�䡣��������Զ���ĳ����ھֵ����ˡ�"
                );
        setup();
    carry_object("/clone/misc/cloth")->wear();
} 
void init()
{
        object me;
        ::init();
        me = this_player();
        if( !query_heart_beat(this_object()) ) set_heart_beat(1); 
        if(random(20)==0 && me && environment(me) == environment() && !me->is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 2, me);
        }
} 
int greeting(object me)
{
        object room;
        if(!me || environment(me) != environment() || me->is_fighting()) return 1;
        if( userp(me) )
        {
                if( !me->query("m_success/�ھ��ڼ�") )
                {
                        command("say ��λ" + RANK_D->query_respect(me)+"���Ϸ���Ҫ�������ϸ������������õ����Ѿ�һ��ս......\nҲ�ã���������������֤�ɡ�\n");
                } else {
                        command("say ��λ" +RANK_D->query_respect(me)+"�����ｫ��һ����ս���ط���С���㻹��ȥ��ȫ�ĵط��ɡ�\n");
                        message_vision("$N����һ�ӣ�һ����͵ľ��罫$n�������ͳ����������¡�\n",this_object(),me);
                   room = find_object("/d/bawang/undertower2");
                        if(!room) room=load_object("/d/bawang/undertower2");
                        me->move(room);
                        message("vision", me->name()+"�������滺������������\n", environment(me), me);
                }
        }
        return 1;
} 
int proceed()
{
        object me;
        object room;
        object note;
        me = this_player();

        if (me->is_fighting()) return 1;
        command("say ��λ" + RANK_D->query_respect(me)+"�������⡰������Ȯ�족���ڼ��ǹ鶫����\n");
        command("consider");
        command("say �Ϸ�Ҳ��������º�������Σ������Һ͵��ֵܶ�������
�鶫�����ڼ�ĵ��ˡ������Ҷ���ƴ�����ܾ��ˣ���������������\n\n\n");
        if(!me->query("m_success/�ھ��ڼ�") ){
                me->set("m_success/�ھ��ڼ�",1);
                me->add("score",100);
        }
        message_vision(HIR"�����ͻȻ����һ����Ц����������죬��ȥ�ɣ���\n"NOR, me);
        message_vision(HIW"һƬ���������İ������������ױȵ��ٶ���$N������
$N�Ѿ��޷���ܣ�ֻ�ñ�Ŀ����������\n"NOR, me);
        message_vision(HIR"\nֻ����$Nһ�����ȣ������ߣ���\n$nֻ����һ����ɽ��������������ػ�������������$n�������Ʊڶ�����
���ɵ���Ѫ���磬һ�������˹�ȥ��\n"NOR,this_object(),me);
        message_vision("���Ժ����У�$N������һƬ��Ҷ��������Ʈ�䣬�ƺ�����һ��������
ס��$N����������\n",me);
        room = find_object("/d/bawang/undertower2");
        if(!room) room=load_object("/d/bawang/undertower2");
        me->unconcious();
        me->move(room);
        message("vision", "������ͻȻ����һ����ȣ����أ�����һ����ֻ��"+me->name()+"������������Ʊڶ�����
�漴һ�������������ɳ�����ס��"+me->name()+"������ʹ"+me->name()+"�����建������������ߵĲݵ��ϡ�\n", environment(me), me);
        message("vision", "�����в��ϴ������أ�ž�����ľ��������ŭ�Ⱥ͵�߳����ö���ҡҡ��׹��
����㵽���㣬���ϵ��д���שʯ����ľ�ɳ����ڵײ㣬����һ������
���صľ��죬������Ȼ�������������������У�������Ӱ�ƺ������Ϸ���
�ɱ���ȥ��\n", environment(me), me);
        message("vision", "����һ�˴ӷ���������"+me->name()+"��ߣ��Ҵ�д��һ��ֽ��������"+me->name()+"���У�
�漴Ҳ׷�����϶�ȥ��\n", environment(me), me);
        note = new(__DIR__"obj/dingxi_note");
        if (note) note->move(me);
        return 1;
}       
