 // (C)1998-2000 Tie Yu
inherit NPC;
int tell_him();
int tell_him2();
void create()
{
        set_name("�岨����", ({ "prince qingbo","qingbo" }) );
        set("gender", "����" );
        set("long","�岨���ǳ�͢�Ժգ�����Ϊ�������ң��Ѿ����ų�ն��Ψ���岨���ӵ������⡣\n");
        set("age", 25);
        set("combat_exp", 500);
        set("attitude", "friendly");
        set("per",30);
        set("chat_chance", 1);
        set("chat_msg", ({
                "�岨�����૵���Ԭ��������Ԭ��������֪�������ˣ�������\n",
        }) );
        set("inquiry", ([
                "Ԭ��" : (: tell_him :),
                "yuanji" : (: tell_him:),
                "ʮ����Բ" : (: tell_him2 :),
                "shiwuyueyuan" : (: tell_him2 :),
        ])); 
        setup();
        carry_object(__DIR__"obj/scloth2")->wear();
} 
int tell_him()
{
 object me;
 me =this_player();
 tell_object(me,"�岨���ӵ���Ԭ�����Ǻ�����÷��������Ϊ�Ҽұ����ų�ն��\n");
 tell_object(me,"���Ѿ�������������ˣ�\n");
 return 1;
} 
int tell_him2()
{
 object me;
 me =this_player();
 if (me->query("m_success/����Ԭ��")==1) {
        message_vision("$N˵��лл������������žۡ�\n",this_object());
   return 1;
 }
 if (me->query("m_success/����Ԭ��")==2) {
        message_vision("$Nʹ�������˵�����ˣ����ˡ�\n",this_object());
        return 1;
 }
 if (me->query("m_success/����Ԭ��")==3) {
        message_vision("$Nŭ���������С�ˣ������ҵ�Ԭ����\n",this_object());
        this_object()->kill_ob(this_player());
        return 1;
 }      
 if(me->query_temp("marks/yuanji")) {
 tell_object(me,"�岨������˻���ߵ����������Ѿ�����Ԭ���ˣ���Ⱦ����ǣ���������󹬰ɣ�\n");
 tell_object(me,"�岨������ɥ�����������ǵ�����ϵ���檣�����Ԭ�����ˣ����ǿ�����Ҳ�������ˣ�\n");
 command("cry");
 me->set_temp("marks/qingbo",1);
 return 1;
 } else return 0;
}         
