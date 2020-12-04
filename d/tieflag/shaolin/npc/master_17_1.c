 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include <combat.h>
int leave();
int damo();
int swit();
int be_guard();
int take_challenge(object me);
void create()
{
    set_name("�ĺ�", ({ "master hu", "master"}) );
    set("vendetta_mark","shaolin");
    set("gender", "����" );
    set("chat_chance", 1);
    set("chat_msg", ({
        name()+"��������һ���ٶ���˭����ȥ�ؾ�¥��\n"
            }) );
    set("age", 84);
    set("per", 35);
    set("agi",30);
    set("int",30);
    set("attitude","friendly");
    set("max_neili", 1500);
    set("neili", 1500);
    set("long",
        "���������������ˣ����ڶ��ֳ������飬����ϲŭ�޳����������ؾ���"
        "�ĵ���������֡�\n");
    create_family("������", 17, "����");
    set("student_title","����");    
    set("combat_exp", 5000000);
    set("no_arrest", 1);
    set("inquiry", ([
        "�׽" : (: damo :),
        "yijinjing" : (: damo :),
        "��Ħ" : (: damo :),
        "damo" : (: damo :),
           "����" : (: damo :), 
        "�ؾ�¥": (: be_guard :),
         "leave" : (: leave :),
        "ʦ��" : (: swit :),
    ]));
    set_skill("move", 160);
    set_skill("dodge", 160);
    set_skill("force", 160);
    set_skill("literate", 150);
    set_skill("unarmed",160);
    set_skill("shaolin-shenfa",150);
    set_skill("jingang-quan",150);
    set_skill("yizhi-chan",150);
    set_skill("damo-jian",160);
    set_skill("hunyuan-yiqi",150);
    set_skill("yiyang-zhi",140);
    set_skill("banruo-zhang",160);
    set_skill("ranmu-daofa",120);
    map_skill("dodge", "shaolin-shenfa");
    map_skill("force", "hunyuan-yiqi");
    map_skill("unarmed", "yiyang-zhi"); 
    setup();
    carry_object(__DIR__"obj/monk_cloth")->wear(); 
} 
int be_guard(){
        object me;
        me = this_player();
        message_vision("$N����������Э�����²���ؾ�¥ʧ�Ե��ɰ���....��....�㲻�������¶����𣿡���answer��\n",this_object()); 
        add_action("do_answer", "answer");
        return 1;
} 
int damo(){
        object me;
        int explvl, budlvl;
        me = this_player();
        explvl = me->query("combat_exp");
        budlvl = me->query_skill("yizhi-chan",1); 
        if(this_object()->is_fighting()){
                return notify_fail("�ĺ��ƺ�����æ��\n");
        }
   if(me->query("marks/�������")){
                message_vision("$N��Ū�����еķ���,����ӽ������ �������ң���Եҵ��ת���������ܣ��Դ�Ե������\n",
                                this_object()); 
                return 1;
        }
        message_vision("$N΢΢һ��ü˵�������׽�˶���������һ��ֻ����Ե֮�ˡ�������\n", this_object()); 
        if(me->query("betrayer") && me->query("class")=="shaolin" && budlvl<150) {
                message_vision("$N�����˿���˵������ͽ������ǰ��ɱ��̫�أ��׽����������Ե�ˡ���\n",this_object());
                return 1;
                }       
        if(me->query("class") != "shaolin") {
                message_vision("$NЦ��������ȷ��Ҷ��֣����ǲ�Ҫ�����ˡ���\n", this_object());
                return 1;
        } else if(explvl > 2400000 && budlvl > 150){
                message_vision(YEL"\n$N���˿�$n������ġ�������һ����"NOR, this_object(), me);
                message_vision(YEL"��̾һ����ԭ����ˣ����գ����ա���\n"NOR, this_object());
                message_vision(YEL"$N����$n˵������Ҫѧ�׽��Ϊʦ����Ҫ��������ѧ�ϵ���Ϊ���ɷ񣿡�\n"NOR, 
                                this_object(), me);
                message_vision(YEL"���������������󣯣�\n"NOR, this_object());  
                add_action("do_accept", "accept");
                me->set_temp("marks/���ĺ�", 1);
                call_out("no_answer", 60, me);  
        } else {
                message_vision("$N���˿�$n����ͽ����������δ��������ǿ�󡣡�����\n", this_object(), me); 
        }       
        return 1;
}  
int do_accept(string arg) {
        object me;
        
        me = this_player();
        if(!arg || (arg != "yes" && arg != "no")){
                return 0;
        }
        if(me->is_fighting()){
                return notify_fail("������æ��\n");
        }
        if(!me->query_temp("marks/���ĺ�")){
                return 0;
        }
   if(this_object()->is_fighting() || this_object()->is_busy()){
                command("say ��������æ���Ȼ�ɡ�����");
                return 1;
        }
        if(arg == "no"){
                remove_call_out("no_answer");
                message_vision("$N���˵�ͷ���������ۣ��૵�������ʧ��Ե������������ϲ�粻����ڤ˳�ڵ�������\n",
                        this_object());
        } else if(arg == "yes"){
                remove_call_out("no_answer");
                message_vision("$N�������аɡ�����������\n", this_object());
                me->set("marks/challenge_xinhu", 1);
        }
        me->delete_temp("marks/���ĺ�"); 
        return 1;
} 
int accept_fight(object me){
        if(this_object()->is_fighting()){
                command("say ��������æ���Ȼ�ɡ�����");
        } else if(!me->query("marks/challenge_xinhu")) {
                message_vision("$N�������ۣ��૵�������ʧ��Ե������������ϲ�粻����ڤ˳�ڵ�������\n", this_object());
                return 0;
        } else if (me->query("marks/�������") == 1) {
                message_vision(YEL"$N���������������þ������������ģ������ľ��������������������񣿡�\n"NOR,
                                this_object());
        } else if (me->query("marks/�������") == 2) {  
                message_vision(YEL"$N���ͷ˵�������գ����ա�������������\n"NOR, this_object()); 
                message_vision(YEL"$N�����ȵ�����δ����δ����ĪԸĪ��δ�����Ծ���������δ���¡������ܽ�񣡡�\n"NOR, 
                                this_object());
        } else if (me->query("marks/�������") == 3) {  
                message_vision(YEL"$N˫�ֺ�ʮ��΢Ц��������ϲ����ϲ��������Ӧ֤�˴������\n"NOR, this_object());
                message_vision(YEL"$N˫�ֺ�ʮ������л��������лʦ��ָ���Խ򡣡�\n"NOR, me); 
                message_vision("\n$N�ʵ�����ֻ���֮�뷨��Ϊ�Ƿ����ȣ�Ϊ�Ƿ����ȣ��������ȣ����Ǻη���˵�����Ƿ����ȣ�\n",
                                this_object());
                message_vision("�кν̶��ɵ�����\n", this_object()); 
                message_vision("$N�����ش𣺡������ڷ��ȣ����ڷ��󡣡�\n", me); 
                message_vision("\n$N���ʵ�������η��Ⱥ󣿡�\n", me); 
                message_vision("$N��ȻԻ����һ����𣬽�����𷨶��óɷ𣬼��Ƿ��ȷ��Ȼʼ��˵ʮ������������������\n",
                                me);
                message_vision("�����з𷨽̣����еóɷ𣬼��Ƿ��ȷ���Ҳ����\n", me); 
           message_vision("$N��$n��Ի��ĵ�һЦ��\n", me, this_object());
                message_vision(HIY"\n$N˵������ҪѰ�ҵĶ������Ѿ�ָ�������ˣ��㻹����ȥ����\n"NOR, this_object());
                me->delete("marks/�������");
                me->delete("marks/challenge_xinhu");
                me->set("marks/����_��ڳɹ�", 1);
                return 0;
        }
        message_vision("\n$N���������С���������\n", this_object());
        return 1;
} 
void win_enemy(object obj){
        message_vision("$Nҡ��ҡͷ�����������������ϧ����ϧ����\n", this_object());    
} 
void lose_enemy(object me) {
        object room;
        
        if(!me->query("marks/�������")) {
                message_vision(HIR"\n$N��Ȼ��ŭ������ͽ����ʦ������Ҳ����ô�ص��֡���$N�����������ָ
��$n��ǰһ�Ρ�\n"NOR, this_object(), me);
                tell_object(me, HIR"\n�����̴��һ�ȣ���ʧȥ��֪����\n"NOR);
                me->set("marks/�������", 1);           
                me->unconcious();
        } else if(me->query("marks/�������") == 1){
                message_vision(HIR"\n�ĺ����һ���������һ�ȥ����������������ƽ�ƣ�����ʳָ�����㡣\n"NOR, this_object());
                tell_object(me, HIR"������ؿ���Ѫ��ӿ����ǰһ�ڣ����˹�ȥ��\n"NOR);
                me->set("marks/�������", 1);
                me->unconcious();
        } else if(me->query("marks/�������") == 2) {
                message_vision(HIR"\nֻ��$N��������˫��Ĵָͬʱ����$n̫��Ѩ��$n��ʧɫ������������\n"NOR, 
                                this_object(), me);
                tell_object(me, HIR"ֻ����ͷ����һ�����ȣ���ǰһ�ڣ����˹�ȥ��\n"NOR); 
                me->set("marks/�������", 1);
                me->unconcious();
        } 
        message("vision", "����Сɳ��������" + me->name()+ "̧�˳�ȥ��\n", environment(me), me);
        room = find_object("/d/songshan/damocave");
        if(!objectp(room)){
                room = load_object("/d/songshan/damocave");
        }
        me->move(room);
   message("vision", "����Сɳ�ְ�" + me->name() + "̧�����ŵ��˵��ϡ�\n", room);
        me->delete_temp("marks/���ĺ�");
} 
void yijing(object me){
        
} 
void no_answer(object me) { 
        message_vision("$N���˵�ͷ���������ۣ��૵�������ʧ��Ե������������ϲ�粻����ڤ˳�ڵ�������\n",
                        this_object()); 
        if(me->query_temp("marks/���ĺ�")){
                me->delete_temp("marks/���ĺ�");
        }
        delete("asking");       
} 
void attempt_apprentice(object me)
{
    if(me->query("once_menpai/shaolin") && me->query("once_menpai/wudang")
        && me->query("marks/bugout") && me->query("class")=="wudang"
                && me->query("combat_exp")>3000000
                && !me->query("marry")) {
        message_vision(HIY"$N˵�����������գ��ຣ���ģ���ͷ�ǰ���ͽ�����������ˣ�\n"NOR,this_object());
        message_vision(HIY"$Nһ�ƻ���$n�Ķ����ϡ�\n"NOR,this_object(),me);
        me->delete_skill("changelaw");
        me->delete_skill("three-sword");
        me->delete_skill("five-steps");
        me->delete_skill("taiji");
        me->delete_skill("taijiforce");
        me->delete_skill("taiji-sword");
        me->delete_skill("kwan-yin-spells");
        if (me->query_skill("incarnation",1)>150) me->set_skill("incarnation",150);
        command("recruit " + me->query("id") );
        me->delete("marks/bugout");
        me->delete("once_menpai/wudang");
        me->add("betrayer", -2);  
        if (me->query("betrayer")<0) me->set("betrayer",0);
        return;
    }
    if(me->query_temp("won_master_yi")||me->query_temp("won_master_17"))
    {
        command("smile");
        command("recruit " + me->query("id") );
        me->delete_temp("won_master_yi");
        me->delete_temp("won_master_17");
        return;
    }
    else
    {
        command("shake");
    }
} 
void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "shaolin");
} 
int do_answer(string arg)
{
    object ob;
    if(arg == "����" )
    {
        command("say �ã���ȥ�ɣ�\n");
        command("say �������ҵ����ͣ����ã�wave�����ſ����ϲؾ�¥��\n");
        ob = new(__DIR__"obj/shouyu");
        if(ob) ob->move(this_player());
        return 1;
    }
    return 0;
} 
void die(){
        message_vision("$N�˺󼸲�΢һ��������ɫ�ָֻ��˺���\n", this_object());
        "/cmds/imm/full"->main(this_object(),"");
}  
void init()
{       
        ::init();
        add_action("do_killing", "kill"); 
} 
int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
        if(!objectp(victim))
                return notify_fail("����û������ˡ�\n");
    if(living(victim))
    {
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "shaolin"&& userp(victim)&&player!=victim)
        {
            message_vision(HIW
"$N��$n�ȵ��������ӷ�,�����徲֮��,�������ɱ��?ʩ����ˡ���ĵ����ˣ�\n"NOR, this_object(),player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
} 
int leave() {
        if (this_player()->query("class")!="shaolin") return 0;
        message_vision(CYN"$N���Ƶ��������ӷ𣬼�����Ե���α�����,�Ժ�Ҳ��Ҫ�ٻ����ˡ�\n"NOR, this_object(),this_player());
        return 1;
}  
int swit () {
        object me;
        me=this_player();
        if((me->query("family/family_name") == query("family/family_name") &&
                me->query("family/master_id") == query("id")) ){
                message_vision(CYN"$N����������Ҵ�ĦԺ�ļ�λʦ��ѧ�գ�ֻ��������ͽ���ϣ���Ҫ���Ŭ���ųɡ�\n",this_object());
                this_player()->set_temp("won_master_17",1);
                return 1;
        }
        return 0;
}
