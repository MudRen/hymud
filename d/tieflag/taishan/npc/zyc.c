 inherit NPC;
int tell_him();
void create()
{
        set_name("������", ({ "zyc" }) );
        set("gender", "����" );
        set("title","��ҩ��");
        set("age", 42);
        set("long", "����һλ����������ɽ,������ҩΪ����������С�
����̤��������ɽ,��������ٲݡ����ڳ������,
������Щ�Ź�,����ҽҩ֮����������֪����������
���־�֢�ĸ��֡�ü�������ԼԼ͸��һ˿����,�·�
��˼����ʲô��\n");
        set("combat_exp", 100000);
        set("attitude", "heroism");
        
        set("skill_public",1);
        set_skill("unarmed", 10);
        set_skill("parry", 10);
        set_skill("dodge", 10);
        //set_skill("herb",100);
        
        set("inquiry", ([
        "zhishang" : (: tell_him :),
        "����" : (: tell_him:),
        "cure" : (: tell_him :),
        ]));
        set("chat_chance", 1);
        set("chat_msg", ({
        "��ҩ�ɼ�����ҩ���ƺ���û��ע����ĵ�����\n",
        }) );
        setup();
        add_money("coin", 1);
        carry_object("/clone/misc/cloth")->wear();
}  
int tell_him()
{
        object me;
        me =this_player();
        if(!me->query("attr_apply")) {
   message_vision("$N����$n���������û���˵���ǣ�Ƥ����ȥ��Щ���ϰ�ҩ�Ϳ����ˡ�\n",
                        this_object(),me);
        return 1;
        } else {
        message_vision("$N����$n���������˿ɲ���ѽ�������ε���û�к�̶����ҩ����\n",
                        this_object(),me);
        }
} 
int recognize_apprentice(object ob)
{
        if(ob->query("free_learn/herb"))
        return 1;
        else {
                if (!random(2)) {
                command ("say ��ѧҩ�����Ȱ��������£�һֱ��˵�и��ڴ�ҩ�ͣ����ܲ���������һ������\n");
                } 
                return notify_fail("\n");
        }
} 
int accept_object(object who, object ob)
{       
        if (ob->query("name")=="�ڴ�ҩ��")
        {
                message_vision("$N��Ц��һ̯��˵��С�϶�����ĺڴ�ҩ�Ͷ��ѳ�ɽ�ˡ�\n",this_object());           
                message_vision("$N˵���������һ���Ҫ��̶����ҩ�������ܲ���������һ�£�\n",this_object());
                return 0;
        }       
        if (ob->query("name")=="��̶��")
        {
                if (who->query_temp("well_frog")) {
                        message_vision("$NЦ�Ǻǵ�˵���ã��á�\n",this_object());               
                        message_vision("$N˵����ѧ�ҵ�ҩ����û���⡣\n",this_object());
                        who->set("free_learn/herb",1);
                        return 1;
                } else 
                        {
                        command("say �ⲻ�����ҵ��İɣ��Ұ����鲻��Ҫ��·�����Ķ�����");
                        return 0;
                        }
        }        
}
