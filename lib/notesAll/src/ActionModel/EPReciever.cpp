#include "EPReciever.h"

Reciever::Reciever()
{
}

Reciever::~Reciever()
{

}

void Reciever::Action()
{
    cout<<"Reciever action ...."<<endl;
}

Command::Command()
{

}

Command::~Command()
{

}

void Command::Excute()
{

}

ConcreteCommand::ConcreteCommand(Reciever *rev)
{
    _rev = rev;
}

ConcreteCommand::~ConcreteCommand()
{
    delete _rev;
}

void ConcreteCommand::Excute()
{
    _rev->Action();
    cout<<"ConcreteCommand "<<endl;
}

Invoker::Invoker(Command *cmd)
{
    _cmd = cmd;
}

Invoker::~Invoker()
{
    delete _cmd;
}

void Invoker::Invoke()
{
    _cmd->Excute();
}

//Reciever *rev = new Reciever();
//Command *cmd = new ConcreteCommand(rev);
//Invoker *inv = new Invoker(cmd);
//inv->Invoke();
