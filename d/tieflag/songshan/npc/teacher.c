 // teacher.c
inherit NPC; 
void create()
{
        set_name("�λ�", ({ "meng huan", "huan" }) );
        create_family("������", 20, "����");
        set("title", "��������");
        set("vendetta_mark","shaolin");
        set("int",5);
        set("skill_public",1);
        set("gender", "����" );
        set("age", 57);
        set("chat_chance", 2);
        set("chat_msg", ({
                "�λ��ֹ���������֪����˭͵�˱��µľ��飿��\n",
        }) );
        set("long",
                "�λ�ԭ����,����ʱ�й���ţ������ǳ��صĸ�ĸ��,�����ڼ��������ɰ�,\n"
                "��ϧΪ��������,��;���������ڿ��ƺ쳾,����Ϊɮ��\n");
        set("attitude", "peaceful");
        set_skill("literate", 150);
        set_skill("buddhism",100);
        setup();
}  
int recognize_apprentice(object ob)
{
        if(ob->query("free_learn/literate"))
        return 1;
        else {
                if( ob->query("m_success/�±�����")) 
                {
                command ("say �ã��ã���Ϊ�������˴󹦣������Ըѧ����ͷ𷨣�Сɮ������������\n");
                ob->set("free_learn/literate", 1);
                return 1;
                }
                command ("say �����¶��ֶ��ѣ�����и�����������˽���ؾ���,Сɮ�ܷ���֮����ɽ̽��,��Ͼ�˼�ʫ��֮��.");
                return 0;
        }
}     
