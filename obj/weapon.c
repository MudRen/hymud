// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit WEAPONTYPE;

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
"qx_snake_poison",
"anqi_poison",
"yf_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

void create()
{
	set_name("WEAPON_SWORD", ({ "WEAPON_ID", "IDTYPE" }));
	set_weight(weighttext);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "unittext");
		set("long", @LONG
LONG_TITLE
LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "ownertext");
		set("ownername", "ownernametext");
		set("value", valuetext);
		set("weapon_prop/intelligence",inttext);
		set("weapon_prop/strength",strtext);
		set("weapon_prop/karey",kartext);
		set("weapon_prop/percao",pertext);
		set("weapon_prop/dexerity",dextext);
		set("weapon_prop/constitution",context);
    set("weapon_prop/dodge", dodgetext);
    set("weapon_prop/parry", parrytest);
    set("weapon_prop/attack", attacktest);
    set("weapon_prop/armor", armortext);
    set("weapon_prop/defense", defensetext);
    
    set("weapon_prop/neili", neilitext);
    set("weapon_prop/qi", qitext);
    set("weapon_prop/jing", jingtext);
    set("weapon_prop/jingli", jinglitext);
    set("weapon_prop/damage", damagetext);

    set("wtypeA",wtypeAtext);
    set("wtypeB",wtypeBtext);
    set("wtypeC",wtypeCtext);
    set("wtypeD",wtypeDtext);
    set("wtypeE",wtypeEtext);
    set("wtypeF",wtypeFtext);
    set("wtypeG",wtypeGtext);
    set("wtypeH",wtypeHtext);
    set("wtypeI",wtypeItext);
    set("wtypeJ",wtypeJtext);
    set("wtypeK",wtypeKtext);
    set("wtypeL",wtypeLtext);
    

                set("skill", ([
                        "name": "skillnametext",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": skilllevtext,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", sharpnesstext);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	set_amount(weaponamount);
	init_TYPEDM(weilitext);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";