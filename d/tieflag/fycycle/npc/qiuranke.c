 inherit NPC;
#include <ansi.h>
int regive_book();
void create()
{
        set_name("��״�", ({ "qiuran han","han" }) );
        set("gender", "����" );
        set("class", "shaolin" ); 
        set("age", 51);
        set("str", 100);
        set("cor", 60);
        set("cps", 60);
        set("con", 50);
        set("int", 50);
        set("max_qi", 50000);
        set("max_jing", 5000);
        set("max_sen", 5000);
        set("max_neili", 5000);
        set("neili", 20000);
        set_temp("apply/attack", 300);
        set_temp("apply/damage", 200);
        set("long", "һ�����ְ����������쳣����״󺺣���һ�״ֲ��ް���
�¿��϶����˲���������ȥ��Щ���ǣ�������Ͷ��֮�䲻��
����¶��һ�ָ���Ӣ�۵����ţ�\n");
        set("chat_chance", 2);
        set("chat_msg", ({
    "��״�����һ���ķ�Ҿ������˵�������º������ϡ�·����أ�һ��������\n����Ϊ����ֻΪСŮ���Ѽ��ǣ���δ����żң���˶����������ס�\n",
    "��״��ƺ������������˵Ҷ������Ӣ�����Ǹ�Ӣ�������ôû��������\n",
                }) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.luori" :),
                (: perform_action, "dodge.luoyeqiufeng" :),
                (: exert_function, "shield" :),
        }) );
                set("inquiry", ([
                "���˷糾��" : (: regive_book :),
                "lost fengchen book" : (: regive_book :),
        ]));
         
        set("combat_exp", 20000000);
        set("attitude", "friendly");
        set_skill("yijinjing", 200);
        set_skill("fall-steps", 200);
        set("force_factor", 50);
        set_skill("force", 300);
        set_skill("unarmed", 300);
        set_skill("iron-cloth", 300);
        set_skill("parry", 300);
        set_skill("dodge", 300);
        set_skill("move", 300);
        set_skill("luoriquan", 300);
        map_skill("unarmed","luoriquan");
        map_skill("force","yijinjing");
            map_skill("iron-cloth","yijinjing");
        map_skill("dodge","fall-steps");
        set("no_arrest", 1);
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
int accept_fight(object me)
{
        command("say ���༼��δ����������λ�������֣�\n");
        return 0;
} 
int regive_book()
{
        object item,me;
        int copies;
        me = this_player();
        if (me->query("m_success/Ϸ�糾")&& me->query("�糾��"))
        {
                copies = me->query("m_success/Ϸ�糾");
                if (copies > 3)
                {
                        message_vision("$N��$nŭ��:���������Ĵε���������,��Ȼ�㲻֪��ϧ,�ֺα�����.\n",this_object(),me);
                        return 1;
                }
                me->set("m_success/Ϸ�糾",copies+1);
                item = new(__DIR__"obj/" + me->query("�糾��"));
           item->move(me);
                message_vision("$N�ݸ�$nһ������:��������Ѫ����,��ú��ղ�,�����ٶ�!\n",this_object(),me);
        }else
        {
                message_vision("$N����$n��Ц��:����Ҫ�Գ�Ϊ��.����ƽ�����թ֮ͽ.��ô�ĵ�,������ƭ����.\n",this_object(),me);
                kill_ob(me);
        }
        return 1; 
} 
void zhaoqin(object me){
        object hong;
        
        
        if(me->query("gender") == "Ů��" && 
             !( (string) me->name() == "Ҷ��") ){
                message_vision("$N��Ц�������������λŮ�����ⰳ��СŮ��л�ˡ�\n", this_object());
        } else if (me->query("age") >= 30){
                message_vision("$N΢ŭ��������һ����ͣ��ѵ�Ҫ��Ů���ػ��ô��\n", this_object());
        } else if (me->query("combat_exp") < 300000){
                message_vision("$N���ֵ���ˡ��ֱ�ԣ����²�ѧδ����ȭ�����ۣ�������ذɡ�\n", this_object());
        } else if (me->query("m_success/Ϸ�糾")){
                message_vision("$N���������˹�֪�㣬��������\n", this_object());
        } else {
                
                hong = present("redcloth girl", environment(this_object()));
                message_vision("$N�����ۺ��룬����Ц�����ã�����СŮ����¹����аɣ�\n", this_object());
                me->set_temp("marks/fight_hongfunv", 1);
        }
        return;
} 
void lose_fight(object obj){
        object red, item;
        int i; 
        red = present("redcloth girl", environment(this_object()));
        message_vision("$N������Ц�����ã��ã���ϲ����ң��������ѣ��׺�����������Ӣ�۱�����\n", this_object());
        message_vision("$NҲˬ�ʵ�Ц������磬��ɶ����ˣ�������ϣ�\n", red);
        message_vision("$N���˵�ͷ��\n", this_object());         
        message_vision(CYN"\n$N�ͳ�һ�����֣����Ȼ�ؽ�����$n��\n"NOR, this_object(),obj);
        message_vision("\n$N�������죬̾�����Թ����ƣ����²�ɣ��������׿�Զ��������ʮ�꣬\n", this_object());
        message_vision("�������쳾Ҳ��������Ӣ���ǵ������ˡ�Ҳ�գ���һ����������������������������\n", this_object());
   message_vision("��������λ����Ӣ�ۣ�\n", this_object());   
        message_vision("$N�Ϲ��Ͼ�����糾��\n", obj); 
        if(!obj->query("m_success/Ϸ�糾")){
                obj->set("m_success/Ϸ�糾", 1);
                obj->add("combat_exp", 3000);
                obj->add("score", 2000);
        }
//      string *books = ({"book0", "book1", "book2", "book3", "book4"});
//      item = books[random(4)];
        i = random(6);
    item = new(__DIR__"obj/book" + i);
        item->move(obj);
        obj->set("�糾��","book"+i);
        message_vision(HIG"\n$N����Ц�������ã���һ����Ϸ�쳾���������������߰գ�\n"NOR, this_object()); 
        message_vision(HIG"$N����Я�����Ů��֮�֣�ƮȻ��ȥ��\n"NOR, this_object());
        environment(this_object())->remove_flag();
        destruct(red);
        destruct(this_object()); 
        
} 
void win_fight(object obj){
        message_vision("$N������$n�ļ�򣬹�����Ц��������η��ǰ;�����������ٱ����٣�\n", this_object(), obj); 
        obj->set("marks/Ϸ�糾", 1);
        return;
}    
