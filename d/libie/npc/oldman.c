#include <ansi.h>
inherit NPC;
int weapon();
void create()
{
        set_name("ĥ������", ({ "old man","man" }) );
        set("long",
"һͷ�ҷ���˥�϶�����Щȳ�ŵ�ĥ�����ˡ�����һ˫��ʮ���ȶ���ÿ��������
һ�Ѻõ�����ʱ���ܲ�����������������̾����˵��������һ������������
�����Ĵ�ʦ��ȴ��֪Ϊ�������˼�ҵ���������С�򣬾�˵��Ϊ��ҪѰ������
����ʯ��\n"); 
    set("attitude", "friendly"); 
    set("age",72); 
    set("str", 80);
    set("cor", 110);
    set("agi", 50); 
    set("combat_exp", 500000);
        set_skill("unarmed",150);
        set_skill("parry",150);
        set_skill("dodge",150);
        set("inquiry", ([
                "weapon" : (: weapon :),
                "����" : (: weapon :),
                "bingqi" : (: weapon :),
        ]));
    set("chat_chance", 1);
    set("chat_msg", ({
"ĥ��������������������������֮�յ��ܵü����������𹳡���Ҳ�㲻
�������ˡ�\n",
"ĥ�����˳�̾һ�����󷮷���������֪���������м�����������\n",
//              (: random_move :)
    }) );
        set("arrive_msg", "һȳһ�յ����˹�����");
        set("leave_msg", "һȳһ�յ���ȥ��");
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
} 
void init(){
        ::init();
    add_action("do_give","give");
   add_action("do_qian", "qian");
} 
int weapon(){
        object me;
        me = this_player();
        message_vision("$N��̾һ�����������������Եģ������Ե���Ʒ�ֿ�����������\n", this_object());
        message_vision("�����ԣ�������������ѽ����\n", this_object()); 
        return 1;
} 
int do_qian(string arg){
        object me, weapon, stone;
        string obj, item, prop;
        me = this_player();
        if(!arg) {
                return notify_fail("��ҪǶʲô������\n");
        }
        if(!sscanf(arg, "%s with %s", obj, item)) {
                return notify_fail("��Ҫ�����ʲô�����������ʲô������\n");
        }
        weapon = present(obj, me);
        stone = present(item, me);
        if(!objectp(weapon) || !objectp(stone)){
                return notify_fail("��û����Щ������\n");
        }
        if(weapon->query("owner") != me->query("id") || !weapon->query("owner")) {
                return notify_fail("�㲻������Ƕ���������\n");
        }
        if(!stone->query("imbue")){
                return notify_fail("�������������������Ƕ��\n");
        }
        if (stone->name()==HIR"�����൤"NOR && !me->query("m_success/�����൤")) {
                message_vision(YEL"$N̾�˿���������ϧ�����䲻��������\n"NOR,this_object());
                return 1;
        }
        message_vision("$N����" + stone->name() + "��"+weapon->name()+"��\n", this_object());
        weapon->unequip();
        if(weapon->query("weapon_prop")) {
                prop="weapon_prop/";
        }
        if(stone->query("id") == "topaz") {
           if(me->query("imbue/ystone")) {
                        return notify_fail("���Ѿ�����һ����Ƕ��������ˡ�\n");
                }
                message_vision(HIY"\n��¶��ʯ���������Ļ�ɫ��â.... һ�����������"NOR + weapon->name()+"��\n",
                                this_object());
                weapon->add(prop+"flexibility", 5);
                me->set("imbue/ystone", 1);
        } else if(stone->query("id") == "diamond") {
                if(me->query("imbue/bstone")) {
                        return notify_fail("���Ѿ�����һ����Ƕ��������ˡ�\n");
                }
                message_vision(HIC"�̺����ķ���ӨӨ����ɫ��â.... һ�����������"NOR + weapon->name()+"��\n",
                                this_object());
                weapon->add(prop+"spirituality", 5);
                me->set("imbue/bstone", 1);
        } else if(stone->query("id") == "ruby"){
                if(me->query("imbue/rstone")) {
                        return notify_fail("���Ѿ�����һ����Ƕ��������ˡ�\n");
                }
                message_vision(HIR"�����൤�������׵ĺ��.... һ�����������"NOR + weapon->name()+"��\n",
                                this_object());
                weapon->add(prop+"damage", 15);
                weapon->add("base_damage",15);
                me->set("imbue/rstone", 1);
        } else if(stone->query("id") == "amethist") {
                if(me->query("imbue/pstone")) {
                        return notify_fail("���Ѿ�����һ����Ƕ��������ˡ�\n");
                }
                message_vision(HIM"��ڤ�Ͼ��������ĵ���ɫ��â.... һ������ϼ����"NOR + weapon->name()+"��\n",
                                this_object());
                weapon->add(prop+"personality", 5);
                me->set("imbue/pstone", 1);
        } else if(stone->query("id") == "jade") {
                if(me->query("imbue/gstone")) {
                        return notify_fail("���Ѿ�����һ����Ƕ��������ˡ�\n");
                }
                if(!me->query("����B/��Դ_����"))
                        return notify_fail("��ö����������������������壬�޷���Ƕ����������ϡ�\n");
                message_vision(HIG"������䷢���ĳα̵��̹�.... һ�����������"NOR + weapon->name()+"��\n",
                                this_object());
           weapon->add(prop+"intelligence", 2);
                me->set("imbue/gstone", 1);
        }
        destruct(stone);
        weapon->save();
        return 1;
} 
int accept_object(object me, object obj){
        object weapon;
        mixed *inv;
        int i, j;
        inv = all_inventory(me);
        j = 0;
        if(obj->query("imbue")) {
                message_vision(YEL"\n$N��ϸ���˿�$n���е�"NOR+obj->name()+YEL"��ͷ�������ã��ã��˵����\n�����������󡣡�\n"NOR,
                                this_object(), me);
                if (obj->name()==HIR"�����൤"NOR && !me->query("m_success/�����൤")) {
                        message_vision(YEL"$N̾�˿���������ϧ�����䲻��������\n"NOR,this_object());
                        return 0;
                }
                for(i=0; i<sizeof(inv); i++){
                        if(inv[i]->query("owner") == me->query("id") && inv[i]->query("weapon_prop")) {
                                weapon = inv[i];
                                j++;
                        }
                }
                if(!weapon) {
                        message_vision(YEL"\n$N��̧ͷ���˿�$n��������ʯ���������䣬��λ" + RANK_D->query_respect(me) + "����ȥ�����\n�����ı��аɡ���\n"NOR,
                                        this_object(), me);
                        return 0;
                }
                message_vision(YEL"$N��̧ͷ���˿�$n������������Ե�����Ը�Ұ��������Ƕ�������ϣ���\n"NOR,
                                this_object(), me);
                message_vision("������\n", this_object());
        }
        return notify_fail("");
} 
int do_give(string arg) {
        string objectname, acceptor;
        object ob,who; 
   if( sscanf(arg, "%s to %s", objectname, acceptor)==2 )
        { 
        if(acceptor!="ĥ������"&&acceptor!="old man"&&acceptor!="man")
                return 0;
        if(objectname!=MAG"���"NOR&&objectname!="leave hook")
                {command("shake");
                return 0;
                }
        who=this_player();
        ob=present(objectname,who);
        if (ob->query("value")==0)      {
                        command("shake");
                        return 0;
                        }
        if(!objectp(ob)) return 0;
    message_vision(GRN "$N���������ؽ���𹳵ݸ�ĥ�����ˡ�\n"NOR,who); 
        if(!who->query("libie/ĥ������"))
        {
                who->add("score",200);
                who->add("potential",0);
                who->set("libie/ĥ������",1);
        }
        if(!who->query("libie/��𹳶�"))
        {
                ob->unequip();
                ob->set("weapon_prop",0);
                ob->set("name",MAG"�ϵ������"NOR);
                ob->set("value",0);
                ob->set("long","һ�����ι�״�ı���,�����Ѿ��ϵ��ˡ�\n");
        message_vision(YEL "ĥ������С��������ḧ����𹳣��ճյؿ��ţ����˰��Σ���������
������ף���ػ��������ǲ�Ҫ�����˼�ĺá�
\n˵�գ�ĥ�����˵�ָһ������𹳾���������һ����Ϊ���ء�\n"NOR,who);
                return 1;
        }
        else
        {
                if (who->query_temp("libie/���_ĥ������"))
                        {
            message_vision(YEL "ĥ�����˲������$N��������ͷĥ����\n"NOR,who);
                        return 1;
                   }
                who->set_temp("libie/���_ĥ������",1);
                message_vision(HIB"ĥ����������$N��˥�ϵ����ϻ�¶��������㯵����飬���������૵���
�����絶���ѵ������⣿�ð뱾���׻�ȡ��ֽ���������������˲�������
������£�
\nĥ������̾�˿��������������ݸ�$N����ͷ���������ꡱ��ĥ������\n"NOR,who);
        return 1; 
        } 
        }
}   
