#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("Ҷ�º�", ({ "ye gu hong", "ye" }) );
        set("nickname", "С����");
        set("title", "�䵱����");
        set("gender", "����");
        set("age", 26);
        set("no_arrest",1);
        set("long",
                "�԰׵������԰׵��֣��԰׵Ľ���һ�������ѩ��\n"
        );
        set("combat_exp", 400000);                     
        set_skill("move", 80);
        set_skill("dodge", 80);
        set_skill("sword", 80);
        set_skill("parry", 80);
        set_skill("three-sword", 80);
        map_skill("sword", "three-sword");
        map_skill("parry", "three-sword");
        setup();
        carry_object(__DIR__"obj/sword2")->wield();
        carry_object("/clone/misc/cloth")->wear();
} 
void init()
{
        object          me; 
        ::init();
        me = this_player();
        if((interactive(me) && !me->is_ghost()) && !is_fighting()) {
                add_action("do_leave", "leave");
                call_out("greeting", 2, me);
        }
} 
int do_leave(string arg)
{
        object          me, env, gudu, fen; 
        env = environment();
        gudu = present("gu du mei", env);
   if(arg != "gu du mei" || !objectp(gudu)) {
                write("��Ҫ����˭��\n");
                return 1;
        }
        me = this_player();
        fen = present("fen yan zi", env);
        if(!objectp(fen)) {
                remove_call_out("noleave");
                say( HIY "\nҶ�º����������¶��һ˿Ц�ݵ�����л��λ���ѡ�\n"NOR);
                say( HIY "\n�¶������ŵغ��������Ӧ���ҵģ�û�����߲�����Ƭɭ�֣�\n"NOR);
                say( HIR "\nҶ�º�ȵ�����ƥ�򣡻��Ұ���������\n"NOR);
                this_object()->kill_ob(gudu);
                me->set_temp("marks/okleave", 1);
                gudu->set_leader();
        }
        else {
                message_vision(HIY"\n$N��Ҷ�º��:Ҷ����ү������ѳ����ˣ�\n",fen);
                message_vision(HIY"$N��:�ã�\n",this_object());
                message_vision(HIR"$Nһ��������$n�����ţ�\n",this_object(), fen);
                fen->die();
                message_vision(HIY"\nҶ�º��$N˵��:���ǿ������ˣ�\n"NOR,me);
                me->set_temp("marks/okleave", 1);
        }
        return 1;
} 
int greeting(object who)
{
        object  env, tree, fen, gudu; //add by justdoit to judge whether there is fen in tree or in room
        env=environment(this_object());
        tree = present("big tree", env);
        if(!objectp(present("fen yan zi", tree)) && !objectp(present("fen yan zi", env))) {
                fen=find_object(__DIR__"fen");
                if (!objectp(fen)) {
                        fen=load_object(__DIR__"fen");
                }
                fen->move(tree);
        }
        if(gudu=present("gu du mei", environment()) && !who->query_temp("marks/okleave")) {
                message_vision( HIY "\nҶ�º�����Ķ���$N��������λ���Ѱѹ¶������¡�(leave)\n"NOR, who);
                call_out("noleave", 10, who);
   }
        return 1;
} 
int noleave(object who)
{
        object          fen, tree, env; 
        env = environment(this_object());
        if(!is_fighting()) {
                message_vision( HIR "\nҶ�º�����Ķ���$N������λ�����ٲ��ѹ¶������£�Ī����Ҫ�����ˡ�(leave)\n"NOR, who);
                tree = present("big tree", env);
                if(objectp(fen = present("fen yan zi", tree))) {
                        message("vision", "\nï�ܵ�Ҷ�䣬����������һ���죬һ�������Ӱ������\n", environment(this_object()));
                        fen->move(environment(this_object()));
                }
        }
        return 1;
}       
