inherit NPC; 
void create() 
{ 
        set_name("������", ({ "guo dama", "guo" }) ); 
        set("gender", "Ů��" ); 
        set("age", 50); 
        set("long", 
"û���˼ǵù�������ʲôʱ�������԰�ģ����ֻ�ǵõ������Ǵ���һ����� 
�ĺ������ģ�Ҳû����ע�⵽����ʲôʱ�򲻼��ˡ� \n");   
        set("combat_exp", 100); 
        set("attitude", "friendly"); 
        set("per",15); 
        set("chat_chance", 2); 
         
        set("chat_msg", ({ 
                "������̾��һ����˵������������������һ�뽭�����ɼ���������\n", 
                "����������������������Ƕ�����֪����ߵĶ��»���ů�𣿡�\n", 
                "������������æµ�š�\n", 
        }) ); 
        setup(); 
         
    carry_object("/clone/misc/cloth")->wear(); 
    add_money("coin", 20); 
}   
int accept_fight(object me) 
{ 
        command("say ����̫�����������Ķ��֣�"); 
        return 0; 
}          
