// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit DAGGER;

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
	set_name("[1;37m°ËØÔÖ®Ø°Ê×[2;37;0m", ({ "bagua dagger", "dagger" }));
	set_weight(5385);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
[1;37m°ËØÔÓĞ¡°Ğİ¡±¡°Éú¡±¡°ÉË¡±¡°¶Å¡±¡°ËÀ¡±¡°¾°¡±¡°¾ª¡±¡°¿ª¡±Ö®±ğ£¬´´×ÔÖî¸ğÎäºò£¬¼¯ÌìÏÂÍò±äÓÚÒ»Éí£¡
[2;37;0mÕâÊÇÒ»°ÑÓÉÎŞ±È¼áÓ²µÄ[31mÁ÷»¨Ê¯[2;37;0mÖÆ³É£¬ÖØÊ®½ïÆßÁ½ÆßÇ®µÄ[1;37m°ËØÔÖ®Ø°Ê×[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;31mÌìÏÂÎŞË«[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[33mÍÁ[2;37;0m:[1;31m´´ÊÀ[2;37;0m [37mÌì[2;37;0m:[1;31mÎŞË«[2;37;0m [40mµØ[2;37;0m:[35m±ê×¼[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;33mÃğÊÀ[2;37;0m ¸£Ô´:[32m´Ö²Ú[2;37;0m 
ÌìĞş:[32m´Ö²Ú[2;37;0m ÌåÁé:[34mÏ¸Ëé[2;37;0m ×ÏÊ¯:[32m´Ö²Ú[2;37;0m ÉÁµç:[31m¾«ÖÂ[2;37;0m 
³¤Éú:[35m±ê×¼[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 25000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",31);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",36);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 34);
    set("weapon_prop/attack", 65);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 28);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 56);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",14);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",12);
    set("wtypeJ",5);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "club",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 19);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_dagger(1071);
	setup();
}



#include "/obj/ritem/weaponzy.h";