// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit WHIP;

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
	set_name("[1;37mÌ«°×Ö®±Ş[2;37;0m", ({ "taibai whip", "whip" }));
	set_weight(2454);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "¸ù");
		set("long", @LONG
[1;37m
		ÕÔ¿ÍçÏºúÓ§  Îâ¹³ËªÑ©Ã÷		Òø°°ÕÕ°×Âí  ìªí³ÈçÁ÷ĞÇ
		Ê®²½É±Ò»ÈË  Ç§Àï²»ÁôĞĞ		ÊÂÁË·÷ÒÂÈ¥  Éî²ØÉíÓëÃû
		ÏĞ¹ıĞÅÁêÒû  ÍÑ½£Ï¥Ç°ºá		½«ÖË¡õÖìº¥  ³ÖõüÈ°ºîÙø
		Èı±­ÍÂÈ»Åµ  ÎåÓüµ¹ÎªÇá		ÑÛ»¨¶úÈÈáá  ÒâÆøËØÄŞÉú
		¾ÈÕÔ»Ó½ğé³  ºªµ¦ÏÈÕğ¾ª		Ç§Çï¶ş×³Ê¿  ĞúºÕ´óÁº³Ç
		×İËÀÏÀ¹ÇÏã  ²»²ÑÊÀÉÏÓ¢		Ë­ÄÜÊé¸óÏÂ  °×Ê×Ì«Ğş¾­
[2;37;0mÕâÊÇÒ»¸ùÓÉÎŞ±È¼áÓ²µÄ[31mÁ÷»¨Ê¯[2;37;0mÖÆ³É£¬ÖØËÄ½ï¾ÅÁ½ÁãÇ®µÄ[1;37mÌ«°×Ö®±Ş[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;35m¾øÊÀº±¼û[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[31m»ğ[2;37;0m:[1;31mÎŞË«[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;33mÃğÊÀ[2;37;0m ¸£Ô´:[32m´Ö²Ú[2;37;0m 
ÌìÔ¨:[32m´Ö²Ú[2;37;0m ×ÏÊ¯:[32m´Ö²Ú[2;37;0m 

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
		set("weapon_prop/karey",34);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",36);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 31);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",12);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "cuff",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 21);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_whip(989);
	setup();
}



#include "/obj/ritem/weaponzy.h";