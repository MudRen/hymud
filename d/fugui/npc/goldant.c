#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIY"������"NOR, ({ "gold ant", "ant" }) );
        set("long",
                "�����ϴ��ż�����������·����������������ź��룬�۽��������ƣ�\n����˭���Ὣ�����ɸ��������С���ӡ�\n");
        set("chat_chance",2);
        set("chat_msg", ({
                "������¶��һ���ĳ���������ɫ���૵������Թű�������Ӣ�ۣ���\n���Ͻ��ݺ����¶��꣬ȴ���ǰѲ���֮�����޷��õ���ʵ���ǲ����İ�����\n",
                "�������૵�������ɽ����̫���ӻ���ʲô����ֻ���Ҳ���������ı�������\n",
                "�����ϵ������ҳ��ֵĺ��񽣲�֪���ĸ���Ƥ͵���ˡ���\n"
                        })  ); 
        set("combat_exp", 300000+ random (100000));
        set("max_jing",1000);
        set("max_qi",2000);
        set("max_jing",1000);
        set("int",40);
        set("str",20);
        set("cor",30);
        
        set_skill("unarmed",100);
        set_skill("kongshoudao",100);
        map_skill("unarmed","kongshoudao");
        set_skill("dodge",100);
        set_skill("parry",100);
        set("chat_chance_combat",25);
        set("chat_msg_combat",  ({
                        (:perform_action,"unarmed.yaozhan":),
                }));
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
int accept_object(object who, object ob)
{       
        int combat_exp,pot,score;
        if (ob->query("name")==HIG "������"NOR) 
        {
                if( this_player()->query_temp("marks/������") && this_player()->query_temp("marks/������") &&this_player()->query_temp("marks/������") )
           {
                        if( !this_player()->query("m_success/�ɹ�����"))
                        {
                                this_player()->set("m_success/�ɹ�����",1);
                                combat_exp = 500 + random(500);
                                pot = 200 + random(200);
                                score = 100 + random(100);
                                tell_object(who,HIW"�㱻�����ˣ�\n\t\t" +
                                chinese_number(combat_exp) + "��ʵս����\n\t\t"+
                                chinese_number(pot) + "��Ǳ��\n\t\t" +
                                chinese_number(score) + "������\n" +NOR);
                                this_player()->add("combat_exp",combat_exp);
                                this_player()->add("potential",pot);
                                this_player()->add("score",score);
                        }
                        this_player()->delete_temp("marks/������");
                        this_player()->delete_temp("marks/������");
                        this_player()->delete_temp("marks/������");                     
                        write("���������쳤Ц�������úúã���Ȼ����������ر����������������أ���\n");
                        return 1;
                }
                command("thank "+this_player()->query("id"));
        }
        if (ob->query("name")==HIG "���̽�"NOR) 
        {
                command("thank "+this_player()->query("id"));
                this_player()->set_temp("marks/goldant",1);
                write("�����ϺǺ�Ц����������������ر����ҾͲ��������ˡ���\n");
                return 1;
        }
        if (ob->query("name")=="����̽�") 
        {
                command("thank "+this_player()->query("id"));
                this_player()->set_temp("marks/goldant",1);
                write("�����Ϻ������Ц���������Ƕ�л�ˣ����ҽ����ϣ���Ȼ����͵�˽��� �����һر�����\n�ҾͲ��������ˡ���\n");
                return 1;
        }
        write("������ҡ��ҡͷ���ٺ�һЦ������������ͭ������������Ҷ���һ��𡣡�\n");
        return 0;
}  
                                
