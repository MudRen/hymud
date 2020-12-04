 // tea_waiter.c
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
int tell_him();
int stone();
void create()
{
        set_name("������", ({ "fatman" }) );
        set("gender", "����" );
        set("age", 40);
        set("long",
                "һ���װ����ֵİ����ӣ���Ϊ��̫���ˣ�����Ҫ����ϴ�衣\n");
                set("combat_exp", 5);
        set("chat_chance", 1);
        set("chat_msg", ({
                "������ָ���㼥Ц�����㣮������һ��ֻ�������\n",
                                "�����Ӻߵ�����Բ֮ҹ���Ͻ�֮�ۣ�Ҷ����Ӯ���ˣ���\n",
                        "������̾�˿�������ʧ�����ˣ����⡣����\n",
                                "���������ص��������˵�����ʯ������\n",
        }) ); 
        set("inquiry", ([
                "sword" : (: tell_him :),
                "����" : (: tell_him:),
                "stone" : (: stone :),
                "�����ʯ" : (: stone :),
        ])); 
        set("attitude", "friendly");
        set("cps", 25);
        set("cor", 30);
        set("rank_info/respect", "�ָ�");
        set("vendor_goods", ({
                __DIR__"obj/dogmed",
        }));
        setup();
        carry_object("/clone/misc/cloth")->wear(); 
} 
void init(){
        add_action("do_buy", "buy");add_action("do_list", "list");
        add_action("do_look", "look"); 
} 
int stone(){
        object me;
        me = this_player();
        message_vision(YEL"\n$N�ź���˵��������ϧ������Ҳ���Ǻ������ֻ��˵�Ǽ�����������ʯͷ��\n"NOR, this_object());
        message_vision(YEL"������ǰЩ�����и����������С��������������Ҳ����֪��һЩ��Ϣ����\n"NOR,this_object());
        return 1;       
} 
int tell_him()
{
    object me;
    me =this_player();
        if(me->query_temp("marks/sword_asked")) {
    tell_object(me,"�����ӵ����ȣ�������Ϊ���˸�����ˣ����϶�������ү����˳�ۣ������ֶ��ˣ�\n");
        me->set_temp("marks/sword_almost",1);
        return 1;
        }
    return 0;
} 
int attack() {
        object opponent;
        
        opponent = select_opponent();
        if(objectp(opponent)) {
                set_temp("last_opponent", opponent);
        if(random(8)) {
                    COMBAT_D->fight(this_object(), opponent);
                } else {
                    message_vision("�����ӳ�$N��ȣ��������㿴��������Ӹ��������������\n", opponent);
                    message_vision("�����Ӻ�������$N��һʱ��$N��ǰ�Ŀռ䱻��������ȫ������\n", opponent);
                    message_vision("�����˲����ˣ����޿�����\n", opponent); 
            message_vision(HIW"\n���䡱��һ���������ӽ��ʵʵ��ײ��$N\n$N��ײ��������ļ�ֽè��\n"NOR, opponent);  
            opponent->unconcious();                 
                    message_vision("\n������Ц������ƾ����������������èҲ�����ұ��ԣ� \n", opponent);
                    this_object()->remove_all_killer();
                }
                return 1;
        } else
                return 0;
}  
int do_look(string arg) {
        
        string msg;
        object me, obj;
        me = this_player();
        obj = this_object();
        if (!arg || (arg != ((string) query("id")))) return 0;
        msg="һ���װ����ֵİ����ӣ���Ϊ��̫���ˣ�����Ҫ����ϴ�衣
��������Լ��ʮ���ꡣ
����òƽƽ��
���Ŀ����֣��书�����������������������ƺ����ء�\n"; 
        if(obj->query("max_qi")) {
                msg += "��" + COMBAT_D->eff_status_msg((int)obj->query("eff_qi") * 100 
                                / (int)obj->query("max_qi")) + "\n";
        }
        msg+="��������(Cloth)\n"; 
        tell_object(me, msg);
        return 1;
}
