 // teacher.c
inherit NPC; 
void create()
{
        set_name("����", ({ "chi song", "song" }) );
        set("title", "��������");
        set("gender", "����" );
        set("class","lama");
        set("age", 52);
        set("skill_public",1);
        set("int", 30);
        create_family("������", 21, "����");
        set("long",
                "���ɱ��Ǹ��׸�ɮ�ĵ������ӣ����Ǳ����ݺ���������Ϊ��͵\n"
                "�������ӣ��������ʦ�ţ����ڴ˹ȣ���������˫�㣬����˵��\n"
                "�����ӵ����䡣��˵�������ӵ����䣬�����ɻز���������\n"
                );
       set("chat_chance", 5);
        set("chat_msg", ({
                "����˵����˭�����һ������ӣ��ҽ�ȫ���򴫸�����\n",
                "����˵����ʦ��˵ֻҪ������һ�죬�ҾͲ��ܻز�����������������\n"
        }) ); 
        set("inquiry", ([
                "������": "��....������һ������ʦ�����ɵ��ߵġ�\n",
                "����": "�����ڲ��������ǵĴ������",
        ]) );
        set("attitude", "peaceful");
        set_skill("iron-cloth", 180);
        set_skill("unarmed", 100);
        set_skill("bloodystrike", 80);
        set_skill("force", 100);
        set_skill("bolomiduo", 100);
        map_skill("unarmed", "bloodystrike");
        map_skill("force", "bolomiduo");
        set("combat_exp", 900000);
        setup();
} 
int recognize_apprentice(object ob)
{
        if( !ob->query("marks/song") ){
                say("����˵������ֻ�а��һز����������ҲŻ����....\n");           
                return 0;
        } 
        return 1;
} 
int accept_object(object who, object ob)
{
        int bonus;
        if( ob->name() != "������" && ob->name() != "�Ż�����")
        {
                       say("����˵����������Ҫ����������....\n");
                        return 0;
        }
        if (ob->name() == "������"&& ob->query("nature")!= "real" )
        {
                       say("����˵����������Ҳ������ƭ�ˣ����������Ǽٵ�....\n");
                        return 0;
        }
        if (ob->name()== "�Ż�����")
        {
                if (!who->query("marks/ɱ�˸���")) return 0;
                else {
                say("���ɴ�ʧɫ��ʦ����ʦ���������ˣ���\n");
                say("����̾�˿�����Ҳ����Ҳ�û�ȥ�����ˡ�\n");
                say("����˵����λ"+ RANK_D->query_respect(who)+"��лл�����������Ϣ����\n");
                who->set("marks/song",1);
                if(!who->query("m_success/����"))
                {
                who->set("m_success/����",1);
                who->add("score",-1000);
                }
                return 1;
                }
        }
        else
        {
                who->set("marks/song", 1);
                say("����˵�����ã��ã��ã�̫���ˣ��ҵ�ԩ���ڼ�������....\n");
                bonus = random(50);
                who->add("combat_exp", bonus);
           bonus = bonus + random(10);
                who->add("potential", bonus );
                if(!who->query("m_success/����"))
                {
                who->set("m_success/����",1);
                who->add("score",400);
                }
                        return 1;       
        }
                return 1;
}       
