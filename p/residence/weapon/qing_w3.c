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
	set_name("[1;33m�ӻ���[2;37;0m", ({ "fengyun sword", "sword" }));
	set_weight(6718);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
[1;35m��ν���Ƽʻᣬ��ر�ɫ���̴���ǧ���ħС����һ����
[2;37;0m����һ�����ޱȼ�Ӳ��[37m����[2;37;0m�Ƴɣ���ʮ����������Ǯ��[1;35m����֮��[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �������ޱȷ���������[1;36mն����ħ[2;37;0m��������
������˼����ŷ��ţ�
[1;36m��[2;37;0m:[1;31m����[2;37;0m [1;31mħ[2;37;0m:[1;31m��Ԫ[2;37;0m [1;33m��[2;37;0m:[1;35m����[2;37;0m [36mľ[2;37;0m:[1;32mħ��[2;37;0m [31m��[2;37;0m:[1;31m����[2;37;0m [1;37m��[2;37;0m:[1;32mħ��[2;37;0m 
���滹����һЩ���֣�
����:[1;31m����[2;37;0m ����:[31m����[2;37;0m 
����:[32m�ֲ�[2;37;0m ����:[31m����[2;37;0m ����:[32m�ֲ�[2;37;0m ����:[32m�ֲ�[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m����С[2;37;0m ������һЩ�� [1;32mȭ��[2;37;0m ���ļ��ɡ�

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "qing");
		set("ownername", "����С");
		set("value", 25000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 62);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 39);
    set("weapon_prop/qi", 66);
    set("weapon_prop/jing", 31);
    set("weapon_prop/jingli", 31);
    set("weapon_prop/damage", 34);

    set("wtypeA",11);
    set("wtypeB",9);
    set("wtypeC",0);
    set("wtypeD",14);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",9);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",14);
    set("wtypeL",13);
    

                set("skill", ([
                        "name": "cuff",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 18);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_sword(934);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";