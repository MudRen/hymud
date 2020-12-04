// xie.c
// modified by aiai

#include <armor.h>

inherit BOOTS;

protected string master;

void set_master(string m)
{
        if(!stringp(m) || (m == "") || master)
                return;

        else
                master = m;
}

string query_master() { return master; }

string q_long()
{
        return sprintf( "����һ˫�ú����ݱ�Ĳ�Ь��\n%s",
                master?sprintf("Ь������ %s ����\n",capitalize(master)):"");
}

void create()
{
        set_name("��Ь", ({ "cao xie" }) );
        set_weight(500);

        set("unit","˫");
        set("material", "grass");
        set("armor_prop/armor", 5);
        set("long", (: q_long :));
        setup();
}

int check_quest_giver(object who)
{
        if(!objectp(who)
        || !master
        || (who->query("id") != master))
                return 0;

        return 1;
}
