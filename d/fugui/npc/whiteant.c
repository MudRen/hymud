#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"������"NOR, ({ "white ant", "ant" }) );
        set("long",
                "һ������ѩ�����ѵ��ˣ������ֿ��ֳ�����������ֻ�����ȴ����\n��С�����������߰룬����һ�ߣ����Ƿ��ڳ��ϳ�һ�ӣ��������\nһֻ�����ض��١�\n");
        set("chat_chance",2);
        set("chat_msg", ({
"�����ϰ�Ȼ��Ƴ����һ�ۣ����ֶ���������������������£�������\n�ȼ������ɵ��Ṧ���������ۣ����������ҡ�̣ѩ�޺۰����ϡ���\n�ﶼ�ǲ�ֵһ�ᡣ��\n",
"�����ϵ����������Ṧ���Ϸ���ϲ���Դ���ͬ���·�����˵��\n�������ʲô������ӣ������п�ȥ��һ����\n"
                                })  ); 
        set("combat_exp", 200000);
        set("max_jing",800);
        set("max_qi",1600);
        set("max_jing",800);
        set("int",35);
        set("str",30);
        set("cor",35);
        
        set_skill("dodge",150);
        set_skill("move",150);
        set_skill("unarmed",100);
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
int accept_object(object who, object ob)
{       
        object jinlian;
        if (ob->query("name")=="��粽������") 
        {
           this_player()->set_temp("marks/������",1);
                write("�����ϲ�м�ķ��˷������������¿���������ɫ���أ��Ȼ��̾����\n�������Ҷ����Ȼ�����鴫�������µ�һ��Ȼ���Ǵ��ġ���\n");
                command("thank "+this_player()->query("id"));
                return 1;
        }
        if (ob->query("name")=="�������") 
        {
                command("spank "+this_player()->query("id"));
                this_player()->set_temp("marks/whiteant",1);
                write("����������Ц���������˽��ң����˽��ҡ���\n");
                return 1;
        }
        write("������������������ֵ��С���������ۡ���\n");
        return 0;
}      
