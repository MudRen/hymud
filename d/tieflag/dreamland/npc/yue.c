 // Copyright (C) 2001, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
void dream_return(object me);
void create()
{
    set_name("����", ({ "yue fei" }) );
    set("long",
        "һλ�������ף�����Ʈ����ӧ�����꽫����\n");
    set("attitude", "friendly");
    set("chat_chance", 1);
    set("chat_msg", ({
                "������ɫ���ص����������������૵�����֪���������������ڵ��˺δ�������\n",
                "����������ס��ǹ�ˣ�����Ĺ�ע����ǰ��ս�֡� \n",
    }) );
        set("gender", "����");
    set("title", "�ٱ�");
    set("nickname", "����·������ʹ");
    set("str", 250+random(10));
     set("dex", 250+random(10));
    set("cor", 40);
    set("cps", 25);
    set("per",38);
    set("int",30);
    set("max_qi",7000);
    set("max_jing",5000);
    set("max_sen",5000);
    set("max_neili",2000);
    set("neili",2000);
    set("eff_force",2000);
        set("age",40);
    set("combat_exp", 90000000);
    set_temp("apply/damage",500);
    set("qi", 32000);
	set("max_qi", 32000);
	set("jing", 33800);
	set("max_jing", 33800);
	set("neili", 32000);
	set("max_neili", 32000);
	set("jiali", 200);
	
	set("combat_exp", 1500000);
	set("score", 200000);
	set("shen", 100000);
	 	set_skill("fengmo-zhang",180);
	set_skill("liuhe-zhang",180);
set_skill("dagou-bang",80);
	set_skill("strike",190);
	set_skill("force", 250);             // 
	set_skill("force", 180);             // �����ڹ�
	set_skill("huntian-qigong", 330);    // ��������
	set_skill("dodge", 150);      	     // ��������
	set_skill("xiaoyaoyou", 320);        // ��ң��
	set_skill("parry", 150);             // �����м�
	set_skill("hand", 200);              // �����ַ�

	set_skill("blade", 180);             // ��������
	set_skill("liuhe-dao", 280);       // �������ϵ�
	set_skill("begging", 200);           // �л�����
	set_skill("checking", 200);          // ����;˵
	set_skill("training", 200);          // Ԧ����
	set_skill("strike",285);  // �����Ʒ�

	set_skill("xianglong-zhang",285);

	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");

	
	map_skill("force", "huntian-qigong");
	map_skill("hand",  "suohou-gong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("blade", "liuhe-blade");
	map_skill("parry", "yuejia-qiang");

	set_skill("yuejia-qiang", 880);        // �򹷰���
	set_skill("suohou-gong", 380);        // �򹷰���
set_skill("chansi-shou", 380);        // �򹷰���
set_skill("claw", 380);        // �򹷰���
set_skill("hand", 380);        // �򹷰���	
set_skill("club", 380);        // �򹷰���		
map_skill("parry", "yuejia-qiang");
map_skill("club", "yuejia-qiang");
map_skill("claw", "suohou-gong");
map_skill("hand", "chansi-shou");

	prepare_skill("hand",  "chansi-shou");
prepare_skill("claw",  "suohou-gong");

       set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "club.gong" :),
                (: perform_action, "club.qldj" :),
                (: perform_action, "club.zhtx" :),
                (: command("unwield yuejia qiang") :),
                (: command("wield yuejia qiang") :),
                (: perform_action, "claw.suo" :),
                (: perform_action, "hand.qin" :),                
                (: perform_action, "hand.qinna" :),                
                (: perform_action, "dodge.gjtq" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );
    set_temp("apply/armor",8500);
    set_temp("apply/damage",8500);
    set_temp("apply/dodge",200);
    set_temp("apply/attack",500);
    set_temp("apply/defense",200);
    setup();
    carry_object(__DIR__"obj/kuijia")->wear();
        carry_object(__DIR__"obj/silverhat")->wear();
        carry_object(__DIR__"obj/spear")->wield();
} 
void init(){
        ::init();
        add_action("do_hi", "hi");
        add_action("do_accept", "accept");
        add_action("do_confirm", "confirm");
} 
int do_accept(string arg){
        object me;
        me = this_player();
        if(!me->query_temp("marks/yue_ask")) {
                return 0;
                
        }
        if(arg == "yes") {
                remove_call_out("dream_return");
                message_vision(HIC"\n$N������ѧ���ҵ�ǹ�����Ӵ˾��ǳ�ɱ��ǧ�������У����������������еİ����ˡ�\n"NOR,
                                this_object());
                message_vision(HIC"�����Ը�⣿����������������󣯣�\n"NOR, this_object());
                me->delete_temp("marks/yue_ask");
                me->set_temp("marks/yue_confirm", 1);
                call_out("dream_return", 45);
        } else if(arg == "no"){
                remove_call_out("dream_return");
                dream_return(me);
        }
        return 1;
} 
int do_confirm(string arg){
        object me;
        me = this_player();
        
        if(!me->query_temp("marks/yue_confirm")){
                return 0;
        }
        if(arg == "yes"){
                remove_call_out("dream_return");
                message_vision("$N��$n˵�������ã���������Ҫ�����ֶ�������\n", this_object(), me);
                message_vision("\n�������䣬$NͻȻ�������������㻹�����ȥ������������������$n���顣\n", this_object(), me);
                tell_object(me, WHT"\n��֮����һ�ɸ����Ĵ���ѹ����͸������������ǰ��ɫ�������һƬ��\n"NOR);
                me->set("marks/�ٸ�/����", 1);  
                dream_return(me);
        } else {
                remove_call_out("dream_return");
                dream_return(me);
        }
        return 1;
} 
int do_hi(string arg){
        object me;
        me = this_player();
        if(!arg) {
                return 0;
        } 
        if(arg == "yue fei" && me->query("marks/dreaming_yue")) {
                if(me->query_temp("marks/got_yue_attention")){
                        message_vision("$N˫�ֱ�ȭ�����������˸�Ҿ������λӢ�����ˣ�\n", me);
                        message_vision("\n$N��̾һ���� �������⡣���� ����Ҳ����\n", this_object());
                        message_vision("\n$N���˶��� ��$nһ�ϣ�����λ"+ RANK_D->query_respect(me) + "���ˣ� ˡ����ʧ̬����ʵ�����Թ�˭\n",
                                        this_object(), me);
                        message_vision("������Ψ����ȡ�����պ�����ѡ��� \n", this_object());
                        message_vision("\n$N�þ��������˫Ŀ����$n��һ��һ�ٵ�˵��������Ȼ������ˣ���ĳҲ����\n",
                                        this_object(), me); 
                        message_vision("�ں���ֻ����һ���������ı��죬δ���ϧ�ˡ���ĳԸ���Ҷ��ڣ���֪��λ\n", 
                                        this_object()); 
                        message_vision(RANK_D->query_respect(me) +"��Ը���ܣ����������������󣯣�\n", this_object());
                        me->set_temp("marks/yue_ask", 1);
                   me->delete_temp("marks/got_yue_attention");
                        call_out("dream_return", 30, me);
                } else if(me->query("marks/dreaming_yue")){
                        message_vision("$N˫�ֱ�ȭ�����������˸�Ҿ������λӢ�����ˣ�\n", me);
                        message_vision("\n$N��ɫ���ص�ע����Զ��������ȫû��ע�⵽$n�Ĵ��ڡ�\n", this_object(), me);
                        me->set_temp("marks/hi_yue", 1);
                        remove_call_out("responed");
                        call_out("responed", 10, me);
                } else {
                        return 0;
                }
        } else {
                return 0;
        }
        return 1;
} 
void dream_return(object me){
        object room;
        if(environment(me) != environment(this_object()) || !interactive(me)){
                return 0;
        }
        if(!me->query("marks/�ٸ�/����")) {
                message_vision("$Nҡ��ҡͷ����Ҳ�ա��������� \n", this_object());
                if(me->query("m_success/������")){
                        me->add("score", 500);
                        me->add("combat_exp", 20000);
                        me->add("potential", 10000);
                }
        } else {
                tell_object(me, HIR"\n�������·���������˵�������мǾ��ұ������֡�������\n"NOR);
        }
        set("in_action", 0);
        me->delete_temp("marks/yue_ask");
        me->delete("marks/���������ݺ�����");
        me->delete("marks/����������ƽǹ��");
        me->delete("marks/dreaming_yue");
        tell_object(me, HIY"\n��������Ȼһ����̧ͷ�������Լ�����������⣬ԭ����ֻ�������Ͽ�һ�Ρ�\n\n"NOR);
        room = find_object("/d/jinan/shufang2");
        if(!objectp(room)){
                room = load_object("/d/jinan/shufang2");
   }
        me->move(room);
        me->set("startroom","/d/tieflag/fy/fqkhotel");
        if(!me->query("imbue/yuefei") ){
                me->start_busy(3);
                call_out("imbue_event", 2, me, room);
        }
} 
void responed(object me){
        if(environment(me) != environment(this_object()) || !interactive(me)){
                return 0;
        }
        message_vision(WHT"ͻȻ��������Զ��������һ�����̣�\n"NOR, me);
        message_vision("\n$N���һ�����ü��ˣ������쳤Ц, ��ϲ��˵���������ǵ��������������ˣ���\n", 
                        this_object());
        message_vision("\n$N��ʱ��ͷע�⵽$n, ���ס���һ������λ" + RANK_D->query_respect(me)+"���ǡ���������\n", 
                        this_object(), me);      
        message_vision(YEL"\n$N�´�����$nһ������һ������ͻȻ������֮ɫ������������������\n"NOR, 
                        this_object(), me); 
        message_vision(YEL"$Nҡ��ҡͷ����ɫ������˵��������ô�������� ��ô����������������\n"NOR, 
                        this_object()); 
        me->set_temp("marks/got_yue_attention", 1); 
} 
int imbue_event(object me, object room){
        object weapon, ob, *inv, obj;
        string prop;
        int i; 
        if(!interactive(me) || environment(me) != room) {
                return 0;
        } 
        obj = me->query_temp("weapon");
       
                message_vision(HIR"\nһ˿��ӧƮ�����Ĵӿ���Ʈ����$N��" + weapon->name() + HIR"�ϡ�����\n"NOR,
                                me);
                message_vision(HIR"��˿��ȥ��һ�ƺ��է����$N��" + weapon->name() + HIR"�ϣ�ת������ʧ������\n"NOR, me);
                tell_object(me, "\n�㲻�ɵû��ɸղŵ�һ�е��������ǻá�����\n");

                return 1;
        me->set("imbue/yuefei", 2);
        me->save();
        return 1;
}  
