// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit SWORD;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

void create()
{
	set_name("[1;31m������Ӱ��[2;37;0m", ({ "wuji sword", "sword" }));
	set_weight(7927);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
[1;32m�����Ѵ�����뻯���Ƿ��켫���������֮���磡��˵������ڣ������⡰�޼�����
[2;37;0m����һ���ɾ��Լ�Ӳ��[37m����[2;37;0m�Ƴɣ���ʮ��������Ǯ��[1;32m�޼�֮��[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m ���������Է���������[1;33m������ƥ[2;37;0m��������
������˼����ŷ��ţ�
[1;31mħ[2;37;0m:[1;35m����[2;37;0m [32mˮ[2;37;0m:[1;36m����[2;37;0m [1;35m��[2;37;0m:[1;36m����[2;37;0m 
[1;37m��[2;37;0m:[1;31m����[2;37;0m [1;34m��[2;37;0m:[1;35m����[2;37;0m 
���滹����һЩ���֣�
����:[1;31m����[2;37;0m ����:[34mϸ��[2;37;0m ��Դ:[34mϸ��[2;37;0m 
����:[32m�ֲ�[2;37;0m ����:[33m�ܸ�[2;37;0m 
����:[35m��׼[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m����[2;37;0m ������һЩ�� [1;32mȭ��[2;37;0m ���ļ��ɡ�

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "bbm");
		set("ownername", "����");
		set("value", 25000);
		set("weapon_prop/intelligence",27);
		set("weapon_prop/strength",24);
		set("weapon_prop/karey",28);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",40);
		set("weapon_prop/constitution",36);
    set("weapon_prop/dodge", 32);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 43);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 32);
    
    set("weapon_prop/neili", 40);
    set("weapon_prop/qi", 50);
    set("weapon_prop/jing", 24);
    set("weapon_prop/jingli", 32);
    set("weapon_prop/damage", 48);

    set("wtypeA",0);
    set("wtypeB",4);
    set("wtypeC",7);
    set("wtypeD",3);
    set("wtypeE",0);
    set("wtypeF",7);
    set("wtypeG",14);
    set("wtypeH",11);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",3);
    set("wtypeL",11);
    

                set("skill", ([
                        "name": "unarmed",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 15);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_sword(1052);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";